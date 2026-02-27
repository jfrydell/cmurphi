----------------------------------------------------------------------
-- Test model for const alias declarations.
--
-- Verifies:
--   1. Const alias snapshots the value at alias-entry time
--   2. Modifying the source does not affect the const alias
--   3. Regular (non-const) aliases still reflect source changes
--   4. Const aliases work with array elements and record fields
----------------------------------------------------------------------

Const
  N: 3;

Type
  val_t: 0..10;
  ind_t: 1..N;
  arr_t: Array[ind_t] Of val_t;
  rec_t: Record
    x: val_t;
    y: val_t;
  End;
  ss_t: 0..10;

Var
  a: arr_t;
  r: rec_t;
  v: val_t;

Procedure test_arg(ss: ss_t);
  Var ss2 : ss_t;
Begin
  Alias test_ss: ss Do
    ss2 := test_ss;
  EndAlias;
End;

Startstate
Begin
  For i: ind_t Do
    a[i] := i;
  End;
  r.x := 5;
  r.y := 7;
  v := 3;
End;

-- Test 1: const alias snapshots an array element
Rule "snapshot array element"
  a[1] < 10
==>
Begin
  Alias const snap: a[1] Do
    a[1] := a[1] + 1;
    -- snap should still hold the old value
    Assert snap = a[1] - 1
      "const alias should snapshot array element value";
  End;
End;

-- Test 2: const alias snapshots a record field
Rule "snapshot record field"
  r.x < 10
==>
Begin
  Alias const snap: r.x Do
    r.x := r.x + 1;
    Assert snap = r.x - 1
      "const alias should snapshot record field value";
  End;
End;

-- Test 3: const alias snapshots a simple variable
Rule "snapshot simple var"
  v < 10
==>
Begin
  Alias const snap: v Do
    v := v + 1;
    Assert snap = v - 1
      "const alias should snapshot simple variable value";
  End;
End;

-- Test 4: regular alias still works as a reference
Rule "regular alias is reference"
  a[2] < 10
==>
Begin
  Alias ref: a[2] Do
    a[2] := a[2] + 1;
    -- ref should track the change (it's a reference)
    Assert ref = a[2]
      "regular alias should be a reference";
  End;
End;

-- Test 5: mixed const and regular aliases in the same block
Rule "mixed aliases"
  a[3] < 10
==>
Begin
  Alias const snap: a[3]; ref: a[3] Do
    a[3] := a[3] + 1;
    Assert snap = a[3] - 1
      "const alias should snapshot in mixed block";
    Assert ref = a[3]
      "regular alias should reference in mixed block";
  End;
End;

-- Test 6: set variable to const alias
Rule "assign alias"
  a[3] < 10 & false
==>
Begin
  Alias
    const orig : a[3];
    const bigger : a[3] + 1;
    nonconst : a[3];
  Do
    nonconst := bigger;
    nonconst := orig;
  End;
End;

-- Keep the state space finite
Invariant "values in range"
  a[1] <= 10 & a[2] <= 10 & a[3] <= 10 & r.x <= 10 & v <= 10;

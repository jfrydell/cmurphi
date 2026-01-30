/* Test of new 2-pass compilation, allowing out of order declarations */

Var
	v: 0..100;

Procedure Foo(val : 0..100);
Begin
    Bar(val);
End;

Procedure Bar(val : 0..100);
Begin
    v := val;
End;

Rule v < 10 ==>
Begin
    Foo(v + 1);
End;

Startstate
Begin
    v := 1;
End;

Invariant v < 10;

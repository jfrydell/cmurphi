/******************************
  Program "ex/improvements/const_alias.m" compiled by "Caching Murphi Release 5.4.9.1"

  Murphi Last Compiled date: "Feb 26 2026"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Caching Murphi Release 5.4.9.1"
#define MURPHI_DATE "Feb 26 2026"
#define PROTOCOL_NAME "ex/improvements/const_alias"
#define BITS_IN_WORLD 48
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.hpp"

/********************
  Decl declaration
 ********************/

class mu_1_val_t: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_val_t& val) { return mu__byte::operator=((int) val); };
  mu_1_val_t (const char *name, int os): mu__byte(0, 10, 4, name, os) {};
  mu_1_val_t (void): mu__byte(0, 10, 4) {};
  mu_1_val_t (int val): mu__byte(0, 10, 4, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_val_t mu_1_val_t_undefined_var;

class mu_1_ind_t: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_ind_t& val) { return mu__byte::operator=((int) val); };
  mu_1_ind_t (const char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1_ind_t (void): mu__byte(1, 3, 2) {};
  mu_1_ind_t (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_ind_t mu_1_ind_t_undefined_var;

class mu_1_arr_t
{
 public:
  mu_1_val_t array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( const char *n, int os);
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  mu_1_arr_t (const char *n, int os) { set_self(n, os); };
  mu_1_arr_t ( void ) {};
  virtual ~mu_1_arr_t ();
  mu_1_val_t& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else {
      if (index==UNDEFVAL) 
	Error.Error("Indexing to %s using an undefined value.", name);
      else
	Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1_arr_t& operator= (const mu_1_arr_t& from)
  {
    for (int i = 0; i < 3; i++)
      array[i].value(from.array[i].value());
    return *this;
  }

friend int CompareWeight(mu_1_arr_t& a, mu_1_arr_t& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1_arr_t& a, mu_1_arr_t& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1_arr_t::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_arr_t::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_arr_t::set_self( const char *n, int os)
{
  char* s;
  name = (char *)n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 1), i * 8 + os);
    delete[] s;
  }
};
mu_1_arr_t::~mu_1_arr_t()
{
}
/*** end array declaration ***/
mu_1_arr_t mu_1_arr_t_undefined_var;

class mu_1_rec_t
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( const char *n, const char *n2, int os);
  void set_self_ar( const char *n, const char *n2, int os);
  void set_self(const char *n, int os);
  mu_1_val_t mu_x;
  mu_1_val_t mu_y;
  mu_1_rec_t ( const char *n, int os ) { set_self(n,os); };
  mu_1_rec_t ( void ) {};

  virtual ~mu_1_rec_t(); 
friend int CompareWeight(mu_1_rec_t& a, mu_1_rec_t& b)
  {
    int w;
    w = CompareWeight(a.mu_x, b.mu_x);
    if (w!=0) return w;
    w = CompareWeight(a.mu_y, b.mu_y);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_rec_t& a, mu_1_rec_t& b)
  {
    int w;
    w = Compare(a.mu_x, b.mu_x);
    if (w!=0) return w;
    w = Compare(a.mu_y, b.mu_y);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_x.MultisetSort();
    mu_y.MultisetSort();
  }
  void print_statistic()
  {
    mu_x.print_statistic();
    mu_y.print_statistic();
  }
  void clear() {
    mu_x.clear();
    mu_y.clear();
 };
  void undefine() {
    mu_x.undefine();
    mu_y.undefine();
 };
  void reset() {
    mu_x.reset();
    mu_y.reset();
 };
  void print() {
    mu_x.print();
    mu_y.print();
  };
  void print_diff(state *prevstate) {
    mu_x.print_diff(prevstate);
    mu_y.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_x.to_state(thestate);
    mu_y.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_rec_t& operator= (const mu_1_rec_t& from) {
    mu_x.value(from.mu_x.value());
    mu_y.value(from.mu_y.value());
    return *this;
  };
};

  void mu_1_rec_t::set_self_ar( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_rec_t::set_self_2( const char *n1, const char *n2, int os ) {
    if (n1 == NULL) {set_self(NULL, 0); return;}
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_rec_t::set_self(const char *n, int os)
{
  name = (char *)n;

  if (name) mu_x.set_self_2(name, ".x", os + 0 ); else mu_x.set_self_2(NULL, NULL, 0);
  if (name) mu_y.set_self_2(name, ".y", os + 8 ); else mu_y.set_self_2(NULL, NULL, 0);
}

mu_1_rec_t::~mu_1_rec_t()
{
}

/*** end record declaration ***/
mu_1_rec_t mu_1_rec_t_undefined_var;

const int mu_N = 3;
/*** Variable declaration ***/
mu_1_arr_t mu_a("a",0);

/*** Variable declaration ***/
mu_1_rec_t mu_r("r",24);

/*** Variable declaration ***/
mu_1_val_t mu_v("v",40);





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_a.clear();
  mu_r.clear();
  mu_v.clear();
}
void world_class::undefine()
{
  mu_a.undefine();
  mu_r.undefine();
  mu_v.undefine();
}
void world_class::reset()
{
  mu_a.reset();
  mu_r.reset();
  mu_v.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_a.print();
  mu_r.print();
  mu_v.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_a.print_statistic();
  mu_r.print_statistic();
  mu_v.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_a.print_diff(prevstate);
    mu_r.print_diff(prevstate);
    mu_v.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_a.to_state( newstate );
  mu_r.to_state( newstate );
  mu_v.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("assign alias");
  }
  bool Condition(unsigned r)
  {
bool mu__boolexpr0;
  if (!((mu_a[3]) < (10))) mu__boolexpr0 = FALSE ;
  else {
  mu__boolexpr0 = (mu_false) ; 
}
    return mu__boolexpr0;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    while (what_rule < 1 )
      {
	if ( ( TRUE  ) ) {
bool mu__boolexpr1;
  if (!((mu_a[3]) < (10))) mu__boolexpr1 = FALSE ;
  else {
  mu__boolexpr1 = (mu_false) ; 
}
	      if (mu__boolexpr1) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 0;
    }
  }

  void Code(unsigned r)
  {
{
  const mu_1_val_t mu_orig = mu_a[3];
  const int mu_bigger = (mu_a[3]) + (1);
  mu_1_val_t& mu_nonconst = mu_a[3];
mu_nonconst = mu_bigger;
if (mu_orig.isundefined())
  mu_nonconst.undefine();
else
  mu_nonconst = mu_orig;
}
  };

};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("mixed aliases");
  }
  bool Condition(unsigned r)
  {
    return (mu_a[3]) < (10);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 1;
    while (what_rule < 2 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_a[3]) < (10)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 1;
    }
  }

  void Code(unsigned r)
  {
{
  const mu_1_val_t mu_snap = mu_a[3];
  mu_1_val_t& mu_ref = mu_a[3];
mu_a[3] = (mu_a[3]) + (1);
if ( !((mu_snap) == ((mu_a[3]) - (1))) ) Error.Error("Assertion failed: const alias should snapshot in mixed block");
if ( !((mu_ref) == (mu_a[3])) ) Error.Error("Assertion failed: regular alias should reference in mixed block");
}
  };

};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("regular alias is reference");
  }
  bool Condition(unsigned r)
  {
    return (mu_a[2]) < (10);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 2;
    while (what_rule < 3 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_a[2]) < (10)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 2;
    }
  }

  void Code(unsigned r)
  {
{
  mu_1_val_t& mu_ref = mu_a[2];
mu_a[2] = (mu_a[2]) + (1);
if ( !((mu_ref) == (mu_a[2])) ) Error.Error("Assertion failed: regular alias should be a reference");
}
  };

};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("snapshot simple var");
  }
  bool Condition(unsigned r)
  {
    return (mu_v) < (10);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 3;
    while (what_rule < 4 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_v) < (10)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 3;
    }
  }

  void Code(unsigned r)
  {
{
  const mu_1_val_t mu_snap = mu_v;
mu_v = (mu_v) + (1);
if ( !((mu_snap) == ((mu_v) - (1))) ) Error.Error("Assertion failed: const alias should snapshot simple variable value");
}
  };

};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("snapshot record field");
  }
  bool Condition(unsigned r)
  {
    return (mu_r.mu_x) < (10);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 4;
    while (what_rule < 5 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_r.mu_x) < (10)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 4;
    }
  }

  void Code(unsigned r)
  {
{
  const mu_1_val_t mu_snap = mu_r.mu_x;
mu_r.mu_x = (mu_r.mu_x) + (1);
if ( !((mu_snap) == ((mu_r.mu_x) - (1))) ) Error.Error("Assertion failed: const alias should snapshot record field value");
}
  };

};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    return tsprintf("snapshot array element");
  }
  bool Condition(unsigned r)
  {
    return (mu_a[1]) < (10);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 5;
    while (what_rule < 6 )
      {
	if ( ( TRUE  ) ) {
	      if ((mu_a[1]) < (10)) {
		if ( ( TRUE  ) )
		  return;
		else
		  what_rule++;
	      }
	      else
		what_rule += 1;
	}
	else
	  what_rule += 1;
    r = what_rule - 5;
    }
  }

  void Code(unsigned r)
  {
{
  const mu_1_val_t mu_snap = mu_a[1];
mu_a[1] = (mu_a[1]) + (1);
if ( !((mu_snap) == ((mu_a[1]) - (1))) ) Error.Error("Assertion failed: const alias should snapshot array element value");
}
  };

};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<1)
    { R0.NextRule(what_rule);
      if (what_rule<1) return; }
  if (what_rule>=1 && what_rule<2)
    { R1.NextRule(what_rule);
      if (what_rule<2) return; }
  if (what_rule>=2 && what_rule<3)
    { R2.NextRule(what_rule);
      if (what_rule<3) return; }
  if (what_rule>=3 && what_rule<4)
    { R3.NextRule(what_rule);
      if (what_rule<4) return; }
  if (what_rule>=4 && what_rule<5)
    { R4.NextRule(what_rule);
      if (what_rule<5) return; }
  if (what_rule>=5 && what_rule<6)
    { R5.NextRule(what_rule);
      if (what_rule<6) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=0) return R0.Condition(r-0);
  if (r>=1 && r<=1) return R1.Condition(r-1);
  if (r>=2 && r<=2) return R2.Condition(r-2);
  if (r>=3 && r<=3) return R3.Condition(r-3);
  if (r>=4 && r<=4) return R4.Condition(r-4);
  if (r>=5 && r<=5) return R5.Condition(r-5);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
return 0;}
void Code(unsigned r)
{
  if (r<=0) { R0.Code(r-0); return; } 
  if (r>=1 && r<=1) { R1.Code(r-1); return; } 
  if (r>=2 && r<=2) { R2.Code(r-2); return; } 
  if (r>=3 && r<=3) { R3.Code(r-3); return; } 
  if (r>=4 && r<=4) { R4.Code(r-4); return; } 
  if (r>=5 && r<=5) { R5.Code(r-5); return; } 
}
int Priority(unsigned short r)
{
  if (r<=0) { return R0.Priority(); } 
  if (r>=1 && r<=1) { return R1.Priority(); } 
  if (r>=2 && r<=2) { return R2.Priority(); } 
  if (r>=3 && r<=3) { return R3.Priority(); } 
  if (r>=4 && r<=4) { return R4.Priority(); } 
  if (r>=5 && r<=5) { return R5.Priority(); } 
return 0;}
char * Name(unsigned r)
{
  if (r<=0) return R0.Name(r-0);
  if (r>=1 && r<=1) return R1.Name(r-1);
  if (r>=2 && r<=2) return R2.Name(r-2);
  if (r>=3 && r<=3) return R3.Name(r-3);
  if (r>=4 && r<=4) return R4.Name(r-4);
  if (r>=5 && r<=5) return R5.Name(r-5);
  return NULL;
}
};
const unsigned numrules = 6;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 6


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_a[mu_i] = mu_i;
};
};
mu_r.mu_x = 5;
mu_r.mu_y = 7;
mu_v = 3;
  };

};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
const rulerec startstates[] = {
{ NULL, NULL, NULL, FALSE},
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_2() // Invariant "values in range"
{
bool mu__boolexpr3;
bool mu__boolexpr4;
bool mu__boolexpr5;
bool mu__boolexpr6;
  if (!((mu_a[1]) <= (10))) mu__boolexpr6 = FALSE ;
  else {
  mu__boolexpr6 = ((mu_a[2]) <= (10)) ; 
}
  if (!(mu__boolexpr6)) mu__boolexpr5 = FALSE ;
  else {
  mu__boolexpr5 = ((mu_a[3]) <= (10)) ; 
}
  if (!(mu__boolexpr5)) mu__boolexpr4 = FALSE ;
  else {
  mu__boolexpr4 = ((mu_r.mu_x) <= (10)) ; 
}
  if (!(mu__boolexpr4)) mu__boolexpr3 = FALSE ;
  else {
  mu__boolexpr3 = ((mu_v) <= (10)) ; 
}
return mu__boolexpr3;
};

bool mu__condition_7() // Condition for Rule "values in range"
{
  return mu__invariant_2( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"values in range", &mu__condition_7, NULL, },
};
const unsigned short numinvariants = 1;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
r:NoScalarset
a:NoScalarset
v:NoScalarset
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  // procedure for explicit representation
  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];

    // Set perm and revperm

    // setting up combination of permutations
    // for different scalarset
    int carry;
    size = 1;
    count = 1;
    for (i=0; i<1; i++)
      {
        carry = 1;
        in[i]= TRUE;
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
  in[0] = TRUE;
  }
}
void PermSet::ResetToSimple()
{
  int i;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<1; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;

  // Setup range for mapping

  // To be In or not to be

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<1; i++)
    {
      in[i] = TRUE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  Presentation = Explicit;
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
if (!nexted) return FALSE;
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_r.MultisetSort();
        mu_a.MultisetSort();
        mu_v.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_val_t::Permute(PermSet& Perm, int i) {};
void mu_1_val_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_val_t::Canonicalize(PermSet& Perm) {};
void mu_1_val_t::SimpleLimit(PermSet& Perm) {};
void mu_1_val_t::ArrayLimit(PermSet& Perm) {};
void mu_1_val_t::Limit(PermSet& Perm) {};
void mu_1_val_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_ind_t::Permute(PermSet& Perm, int i) {};
void mu_1_ind_t::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_ind_t::Canonicalize(PermSet& Perm) {};
void mu_1_ind_t::SimpleLimit(PermSet& Perm) {};
void mu_1_ind_t::ArrayLimit(PermSet& Perm) {};
void mu_1_ind_t::Limit(PermSet& Perm) {};
void mu_1_ind_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_arr_t::Permute(PermSet& Perm, int i)
{
  static mu_1_arr_t temp("Permute_mu_1_arr_t",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1_arr_t::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1_arr_t::Canonicalize(PermSet& Perm){};
void mu_1_arr_t::SimpleLimit(PermSet& Perm){}
void mu_1_arr_t::ArrayLimit(PermSet& Perm) {}
void mu_1_arr_t::Limit(PermSet& Perm){}
void mu_1_arr_t::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1_rec_t::Permute(PermSet& Perm, int i)
{
};
void mu_1_rec_t::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Record with no scalarset variable\n"); };
void mu_1_rec_t::Canonicalize(PermSet& Perm)
{
};
void mu_1_rec_t::SimpleLimit(PermSet& Perm){}
void mu_1_rec_t::ArrayLimit(PermSet& Perm){}
void mu_1_rec_t::Limit(PermSet& Perm)
{
};
void mu_1_rec_t::MultisetLimit(PermSet& Perm)
{
};

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_r.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_r.MultisetSort();
              mu_a.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_a.MultisetSort();
              mu_v.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_v.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_r.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_r.MultisetSort();
          mu_a.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_a.MultisetSort();
          mu_v.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_v.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_r.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_r.MultisetSort();
              mu_a.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_a.MultisetSort();
              mu_v.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_v.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_r.MultisetSort();
      mu_a.MultisetSort();
      mu_v.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_r.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_r.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_a.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_a.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_v.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_v.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

};

/********************
  Include
 ********************/
#include "mu_epilog.hpp"

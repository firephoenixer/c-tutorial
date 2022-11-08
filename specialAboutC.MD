## Static or dynamic scoping?
C is static scoping. Whitch means a sub function can't see its father's local variable. Only can see global
variable.

## auto register static extern
auto     --   auto int nNum;         // seems a default local storage variable.
register --   register int counter;  // seems store variable in a fastly accessed space. for frequently var.
static   --   in local scope, it keeps the value of a variable before ended.
              in global scope, it seems keep the variable visual only in the file it declared.
extern   --   use a variable or function defined in other file.















/* --- CODE --- */
let code: char => int;
/* Return the ASCII code of the argument. */

Char.code('a');
/* - : int = 97 */
Char.code("b");
/* Error: This expression has type string but an expression was expected of type char */

/* --- CHR --- */
let chr: int => char;
/* Return the character with the given ASCII code. Raise Invalid_argument "Char.chr" if the argument is outside the range 0--255. */

Char.chr(47);
/* - : char = '/' */
Char.chr(257);
/* Exception: Invalid_argument("Char.chr"). */

/* --- ESCAPED --- */
let escaped: char => string;
/* Return a string representing the given character, with special characters escaped following the lexical conventions of OCaml. */

Char.escaped('\\');
/* - : string = "\\\\" */

/* --- LOWERCASE --- */
let lowercase: char => char;
/* Convert the given character to its equivalent lowercase character. */

Char.lowercase('A');
/* - : char = 'a' */
Char.lowercase('a');
/* - : char = 'a' */

/* --- UPPERCASE --- */
let uppercase: char => char;
/* Convert the given character to its equivalent uppercase character.*/

Char.uppercase('a');
/* - : char = 'A' */
Char.uppercase('A');
/* - : char = 'A' */

/* --- TYPE --- */
type t = char;
/* An alias for the type of characters, used by compare below */

/* --- COMPARE --- */
let compare: (t, t) => int;
/* The comparison function for characters, with the same specification as Pervasives.compare. Along with the type t, this function compare allows the module Char to be passed as argument to the functors Set.Make and Map.Make. */

Char.compare('b', 'b');
/* - : int = 0 */
Char.compare('a', 'b');
/* - : int = -1 */
Char.compare('b', 'a');
/* - : int = 1 */

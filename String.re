/*String operations.
A string is an immutable data structure that contains a fixed-length sequence of (single-byte) characters. Each character can be accessed in constant time through its index.

Given a string s of length l, we can access each of the l characters of s via its index in the sequence. Indexes start at 0, and we will call an index valid in s if it falls within the range [0...l-1] (inclusive). A position is the point between two characters or at the beginning or end of the string. We call a position valid in s if it falls within the range [0...l] (inclusive). Note that the character at index n is between positions n and n+1.

Two parameters start and len are said to designate a valid substring of s if len >= 0 and start and start+len are valid positions in s.
*/

/* --- LENGTH --- */
let length: string => int;
/* Return the length (number of characters) of the given string.*/
String.length("horses");
/* - : int = 6 */
String.length("");
/* - : int = 0 */

/* --- GET --- */
let get: (string, int) => char;
/*String.get s n returns the character at index n in string s. You can also write s.[n] instead of String.get s n. Raise Invalid_argument if n not a valid index in s. */

String.get("horse",0);
/* - : char = 'h' */
String.get("horse", 5);
/* Exception: Invalid_argument("index out of bounds"). - Consider using a safe version of this function */

/* --- MAKE --- */
let make: (int, char) => string;
/* String.make n c returns a fresh string of length n, filled with the character c. Raise Invalid_argument if n < 0 or n > Sys.max_string_length. */

String.make(5, 'b');
/* - : string = "bbbbb" */
String.make(0, 'b');
/* - : string = "" */
String.make(0, "b");
/* Error: This expression has type string but an expression was expected of type char */

/* --- INIT --- */
let init: (int, int => char) => string;
/* String.init n f returns a string of length n, with character i initialized to the result of f i (called in increasing index order). Raise Invalid_argument if n < 0 or n > Sys.max_string_length. */

String.init(10, x => 'x');
/* - : string = "xxxxxxxxxx" */
String.init(26, x => {
    Char.chr(Char.code('a') + x)
});
/* - : string = "abcdefghijklmnopqrstuvwxyz" */

/* --- SUB --- */
let sub: (string, int, int) => string;
/* String.sub s start len returns a fresh string of length len, containing the substring of s that starts at position start and has length len. Raise Invalid_argument if start and len do not designate a valid substring of s. */

String.sub("not very well", 9, 4);
/* - : string  = "well" */
String.sub("not very well", 9, 4);
/* Exception: Invalid_argument("String.sub / Bytes.sub"). */
String.sub("not very well", -1, 4);
/* Exception: Invalid_argument("String.sub / Bytes.sub"). */

let blit: (string, int, bytes, int, int) => unit;
/* Same as Bytes.blit_string. */

/* --- CONCAT --- */
let concat: (string, list(string)) => string;
/* String.concat sep sl concatenates the list of strings sl, inserting the separator string sep between each. Raise Invalid_argument if the result is longer than Sys.max_string_length bytes. */

String.concat(", ", ["plop", "slop", "drop"]);
/* - : string = "plop, slop, drop" */

/* --- ITER --- */
let iter: (char => unit, string) => unit;
/* String.iter f s applies function f in turn to all the characters of s. It is equivalent to f s.[0]; f s.[1]; ...; f s.[String.length s - 1]; (). */

String.iter(x => Js.Log(x), "dog");
/* Runs Js.Log('d'); Js.Log('o'); Js.Log('g'); */

let iteri: ((int, char) => unit, string) => unit;
/* Same as String.iter, but the function is applied to the index of the element as first argument (counting from 0), and the character itself as second argument. */

let map: (char => char, string) => string;
/* String.map f s applies function f in turn to all the characters of s (in increasing index order) and stores the results in a new string that is returned. */

let mapi: ((int, char) => char, string) => string;
/* String.mapi f s calls f with each character of s and its index (in increasing index order) and stores the results in a new string that is returned . */

let trim: string => string;
/* Return a copy of the argument, without leading and trailing whitespace. The characters regarded as whitespace are: ' ', '\012', '\n', '\r', and '\t'. If there is neither leading nor trailing whitespace character in the argument, return the original string itself, not a copy.
Since 4.00.0
let escaped: string => string;
Return a copy of the argument, with special characters represented by escape sequences, following the lexical conventions of OCaml. If there is no special character in the argument, return the original string itself, not a copy. Its inverse function is Scanf.unescaped.
Raise Invalid_argument if the result is longer than Sys.max_string_length bytes.
let index: (string, char) => int;
String.index s c returns the index of the first occurrence of character c in string s.
Raise Not_found if c does not occur in s.
let rindex: (string, char) => int;
String.rindex s c returns the index of the last occurrence of character c in string s.
Raise Not_found if c does not occur in s.
let index_from: (string, int, char) => int;
String.index_from s i c returns the index of the first occurrence of character c in string s after position i. String.index s c is equivalent to String.index_from s 0 c.
Raise Invalid_argument if i is not a valid position in s. Raise Not_found if c does not occur in s after position i.
let rindex_from: (string, int, char) => int;
String.rindex_from s i c returns the index of the last occurrence of character c in string s before position i+1. String.rindex s c is equivalent to String.rindex_from s (String.length s - 1) c.
Raise Invalid_argument if i+1 is not a valid position in s. Raise Not_found if c does not occur in s before position i+1.
let contains: (string, char) => bool;
String.contains s c tests if character c appears in the string s.
let contains_from: (string, int, char) => bool;
String.contains_from s start c tests if character c appears in s after position start. String.contains s c is equivalent to String.contains_from s 0 c.
Raise Invalid_argument if start is not a valid position in s.
let rcontains_from: (string, int, char) => bool;
String.rcontains_from s stop c tests if character c appears in s before position stop+1.
Raise Invalid_argument if stop < 0 or stop+1 is not a valid position in s.
let uppercase: string => string;
Return a copy of the argument, with all lowercase letters translated to uppercase, including accented letters of the ISO Latin-1 (8859-1) character set.
let lowercase: string => string;
Return a copy of the argument, with all uppercase letters translated to lowercase, including accented letters of the ISO Latin-1 (8859-1) character set.
let capitalize: string => string;
Return a copy of the argument, with the first character set to uppercase.
let uncapitalize: string => string;
Return a copy of the argument, with the first character set to lowercase.
type t = string;
An alias for the type of strings.
let compare: (t, t) => int;
The comparison function for strings, with the same specification as Pervasives.compare. Along with the type t, this function compare allows the module String to be passed as argument to the functors Set.Make and Map.Make.*/

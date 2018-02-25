/* --- LENGTH --- */
let length: list('a) => int;
/* Return the length (number of elements) of the given list. */

List.length([1,2,3,4]);
/* - : int = 4 */
List.length(["hello","world"]);
/* - : int = 2 */

/* --- HD (head) --- */
let hd: list('a) => 'a;
/* Return the first element of the given list. Raise Failure "hd" if the list is empty. */

List.hd([2,3,4,5]);
/* - : int = 2 */
List.hd([]);
/* Exception: Failure("hd"). Consider using an option-based version of this function instead */

/* --- TL (tail) --- */
let tl: list('a) => list('a);
/* Return the given list without its first element. Raise Failure "tl" if the list is empty. */

List.tl([1,2,3,4]);
/* - : list(int) = [2, 3, 4] */
List.tl([]);
/* Exception: Failure("tl"). Consider using an option-based version of this function instead */

/* --- NTH --- */
let nth: (list('a), int) => 'a;
/* Return the n-th element of the given list. The first element (head of the list) is at position 0. Raise Failure "nth" if the list is too short. Raise Invalid_argument "List.nth" if n is negative. */

List.nth([1,2,3,4,5], 1);
/* - : int = 2 */
List.nth([1,2,3,4,5], 5);
/* Exception: Failure("nth"). Consider using an option-based version of this function instead */
List.nth([1,2,3,4,5], -1);
/* Exception: Invalid_argument("List.nth"). Consider using an option-based version of this function instead */

/* --- REV (reverse) --- */
let rev: list('a) => list('a);
/* List reversal. */

List.rev([1,2,3,4,5]);
/* - : list(int) = [5, 4, 3, 2, 1] */
List.rev(["bed","the","shit"]);
/* - : list(string) = ["shit", "the", "bed"] */

/* --- APPEND --- */
let append: (list('a), list('a)) => list('a);
/* Catenate two lists. Same function as the infix operator @. Not tail-recursive (length of the first argument). The @ operator is not tail-recursive either. */

List.append([1,2,3], [4,5,6]);
/* - : list(int) = [1, 2, 3, 4, 5, 6] */
List.append(["let's","plop","these"],["strings","together"]);
/* - : list(string) = ["let's", "plop", "these", "strings", "together"] */

/* --- REV_APPEND (reverse append) --- */
let rev_append: (list('a), list('a)) => list('a);
/* List.rev_append l1 l2 reverses l1 and concatenates it to l2. This is equivalent to List.rev l1 @ l2, but rev_append is tail-recursive and more efficient. */

List.rev_append([3,2,1], [4,5,6]);
/* - : list(int) = [1, 2, 3, 4, 5, 6] */
List.rev_append(["how","this","is"], ["it","works?"]);
/* - : list(string) = ["is", "this", "how", "it", "works?"] */

/* --- CONCAT (concatenate / join) --- */
let concat: list(list('a)) => list('a);
/* Concatenate a list of lists. The elements of the argument are all concatenated together (in the same order) to give the result. Not tail-recursive (length of the argument + length of the longest sub-list). */

List.concat([["nice","and"],["tidy"],["now"]]);
/* - : list(string) = ["nice", "and", "tidy", "now"] */
List.concat([[1,2,3],[4],[],[5,6]]);
/* - : list(int) = [1, 2, 3, 4, 5, 6] */

/* --- FLATTEN --- */
let flatten: list(list('a)) => list('a);
/* Same as concat. Not tail-recursive (length of the argument + length of the longest sub-list). */

List.flatten([["nice","and"],["tidy"],["now"]]);
/* - : list(string) = ["nice", "and", "tidy", "now"] */
List.flatten([[1,2,3],[4],[],[5,6]]);
/* - : list(int) = [1, 2, 3, 4, 5, 6] */

/* --- ITER (iterate) --- */
let iter: ('a => unit, list('a)) => unit;
/* List.iter f [a1; ...; an] applies function f in turn to a1; ...; an. It is equivalent to begin f a1; f a2; ...; f an; () end. */

List.iter(str => Js.Log(str), ["hello","from","reason"]);
/* no return value, runs Js.Log("hello"); Js.Log("from"); Js.Log("reason"); */

/* --- ITERI (iterate with index) --- */
let iteri: ((int, 'a) => unit, list('a)) => unit;
/* Same as List.iter, but the function is applied to the index of the element as first argument (counting from 0), and the element itself as second argument. */

List.iteri((str,i) => Js.Log(string_of_int(i) ++ str), ["0hello","1from","2reason"]);
/* no return value, runs Js.Log("0hello"); Js.Log("1from"); Js.Log("2reason"); Note the integer value i must be turned into a string and the ++ double add symbol for string concatenation */

/* --- MAP --- */
let map: ('a => 'b, list('a)) => list('b);
/* List.map f [a1; ...; an] applies function f to a1, ..., an, and builds the list [f a1; ...; f an] with the results returned by f. Not tail-recursive. */

List.map(str => str ++ "!!", ["now","i'm","excited"]);
/* - : list(string) = ["now!!", "i'm!!", "excited!!"] */
List.map(str => str ++ "!!!!", ["now","i'm","incredible","excited"]);
/* - : list(string) = ["now!!!!", "i'm!!!!", "incredible!!!!", "excited!!!!"] */

/* --- MAPI (map with index) --- */
let mapi: ((int, 'a) => 'b, list('a)) => list('b);
/* Same as List.map, but the function is applied to the index of the element as first argument (counting from 0), and the element itself as second argument. Not tail-recursive. */

List.mapi((index, item) => {
    string_of_int(index + 1) ++ ": " ++ item;
}, ["List","Of","Things","With","Numbers"]);
/* - : list(string) = ["1: List", "2: Of", "3: Things", "4: With", "5: Numbers"] */
List.mapi((index, item) => index * item, [1,2,3,4,5]);
/* - : list(int) = [0, 2, 6, 12, 20] */

/* --- REV_MAP (reverse map) --- */
let rev_map: ('a => 'b, list('a)) => list('b);
/* List.rev_map f l gives the same result as List.rev (List.map f l), but is tail-recursive and more efficient. */

List.rev_map(i => i * 2, [1,2,3,4,5]);
/* - : list(int) = [10, 8, 6, 4, 2] */

/* --- FOLD_LEFT --- */
let fold_left: (('a, 'b) => 'a, 'a, list('b)) => 'a;
/* List.fold_left f a [b1; ...; bn] is f (... (f (f a b1) b2) ...) bn. */

List.fold_left((acc, value) => {
    acc ++ ":" ++ value
}, "", ["words","to","put","together"]);
/* - : string = ":words:to:put:together" */
List.fold_left((acc, value) => {
    acc + (value * 2)
}, 0, [1,2,3,4,5]);
/* - : int = 30 */

/* --- FOLD_RIGHT --- */
let fold_right: (('a, 'b) => 'b, list('a), 'b) => 'b;
/* List.fold_right f [a1; ...; an] b is f a1 (f a2 (... (f an b) ...)). Not tail-recursive. */

List.fold_right((acc, value) => {
    acc ++ ":" ++ value
}, ["words","to","put","together"],"");
/* - : string = "words:to:put:together:" */
List.fold_right((acc, value) => {
    acc + (value * 2)
}, [1,2,3,4,5], 0);
/* - : int = 129 */

/* --- ITER2 (iterate with 2 lists) --- */
let iter2: (('a, 'b) => unit, list('a), list('b)) => unit;
/* List.iter2 f [a1; ...; an] [b1; ...; bn] calls in turn f a1 b1; ...; f an bn. Raise Invalid_argument if the two lists have different lengths. */

List.iter2((text, num) => {
    Js.Log(string_of_int(num) ++ " " ++ text);
}, ["horse","dogs","cats","sofa"],[1,2,10,1]);
/* No return, will run Js.Log("1 horse"); Js.Log("2 dogs"); Js.Log("10 cats"); Js.Log("1 sofa"); */

/* --- MAP2 (map 2 lists) --- */
let map2: (('a, 'b) => 'c, list('a), list('b)) => list('c);
/* List.map2 f [a1; ...; an] [b1; ...; bn] is [f a1 b1; ...; f an bn]. Raise Invalid_argument if the two lists have different lengths. Not tail-recursive. */

List.map2((text, num) => {
    (string_of_int(num) ++ " " ++ text)
}, ["horse","dogs","cats","sofa"],[1,2,10,1]);
/* - : list(string) = ["1 horse", "2 dogs", "10 cats", "1 sofa"] */

/* --- REV_MAP2 (reverse map 2 lists) --- */
let rev_map2: (('a, 'b) => 'c, list('a), list('b)) => list('c);
/* List.rev_map2 f l1 l2 gives the same result as List.rev (List.map2 f l1 l2), but is tail-recursive and more efficient. */

List.rev_map2((text, num) => {
    (string_of_int(num) ++ " " ++ text)
}, ["horse","dogs","cats","sofa"],[1,2,10,1]);
/* - : list(string) = ["1 sofa", "10 cats", "2 dogs", "1 horse"] */

/* --- FOLD_LEFT2 --- */
let fold_left2: (('a, 'b, 'c) => 'a, 'a, list('b), list('c)) => 'a;
/* List.fold_left2 f a [b1; ...; bn] [c1; ...; cn] is f (... (f (f a b1 c1) b2 c2) ...) bn cn. Raise Invalid_argument if the two lists have different lengths. */

List.fold_left2((acc, a, b) => (acc + a + b), 0, [1,2,3,4,5], [0,1,0,1,0]);
/* - : int = 17 */
List.fold_left2((acc, a, b) => (acc + a + b), 0, [1,2,3,4,5], [0,1,0,1]);
/* Exception: Invalid_argument("List.fold_left2"). */

/* --- FOLD_RIGHT2 --- */
let fold_right2: (('a, 'b, 'c) => 'c, list('a), list('b), 'c) => 'c;
/* List.fold_right2 f [a1; ...; an] [b1; ...; bn] c is f a1 b1 (f a2 b2 (... (f an bn c) ...)). Raise Invalid_argument if the two lists have different lengths. Not tail-recursive. */

List.fold_right2((acc, a, b) => (acc + a + b), [1,2,3,4,5], [0,1,0,1,2],0);
/* - : int = 19 */
List.fold_right2((acc, a, b) => (acc + a + b), [1,2,3,4,5], [0,1,0,1],0);
/* Exception: Invalid_argument("List.fold_right2"). */

/* --- FOR_ALL --- */
let for_all: ('a => bool, list('a)) => bool;
/* for_all p [a1; ...; an] checks if all elements of the list satisfy the predicate p. That is, it returns (p a1) && (p a2) && ... && (p an). */

List.for_all(x => x > 5, [1,2,3,4,5]);
/* - : bool = false */
List.for_all(x => x > 5,[6,7,8,9]);
/* - : bool = true */

/* --- EXISTS --- */
let exists: ('a => bool, list('a)) => bool;
/* exists p [a1; ...; an] checks if at least one element of the list satisfies the predicate p. That is, it returns (p a1) || (p a2) || ... || (p an). */

List.exists(x => x > 5, [1,2,3,4]);
/* - : bool = false */
List.exists(x => x > 5, [4,5,6,7]);
/* - : bool = true */

/* --- FOR_ALL2 --- */
let for_all2: (('a, 'b) => bool, list('a), list('b)) => bool;
/* Same as List.for_all, but for a two-argument predicate. Raise Invalid_argument if the two lists have different lengths. */

List.for_all2((a,b) => (a + b) > 5, [1,2,3], [2,3,4]);
/* - : bool = false */
List.for_all2((a,b) => (a + b) > 5, [1,2,3], [5,6,7]);
/* - : bool = true */
List.for_all2((a,b) => (a + b) > 5, [1,2,3], [4,5]);
/* Exception: Invalid_argument("List.for_all2"). */

/* --- EXISTS2 --- */
let exists2: (('a, 'b) => bool, list('a), list('b)) => bool;
/* Same as List.exists, but for a two-argument predicate. Raise Invalid_argument if the two lists have different lengths. */

List.exists2((a,b) => (a + b) > 5, [1,2,3],[3,4,5]);
/* - : bool = true */
List.exists2((a,b) => (a + b) > 10, [1,2,3], [3,4,5]);
/* - : bool = false */
List.exists2((a,b) => (a + b) > 10, [1,2,3], [3,4,5,6]);
/* Exception: Invalid_argument("List.exists2"). */

/* --- MEM (member of) --- */
let mem: ('a, list('a)) => bool;
/* mem a l is true if and only if a is equal to an element of l. */

List.mem(5, [4,6,7,5]);
/* - : bool = true */
List.mem(1, [4,5,6,7]);
/* - : bool = false */

let memq: ('a, list('a)) => bool;
/* Same as List.mem, but uses physical equality instead of structural equality to compare list elements. */

let find: ('a => bool, list('a)) => 'a;
/* find p l returns the first element of the list l that satisfies the predicate p. Raise Not_found if there is no value that satisfies p in the list l. */

let filter: ('a => bool, list('a)) => list('a);
/* filter p l returns all the elements of the list l that satisfy the predicate p. The order of the elements in the input list is preserved. */

let find_all: ('a => bool, list('a)) => list('a);
/* find_all is another name for List.filter. */

let partition: ('a => bool, list('a)) => (list('a), list('a));
/* partition p l returns a pair of lists (l1, l2), where l1 is the list of all the elements of l that satisfy the predicate p, and l2 is the list of all the elements of l that do not satisfy p. The order of the elements in the input list is preserved. */

let assoc: ('a, list(('a, 'b))) => 'b;
/* assoc a l returns the value associated with key a in the list of pairs l. That is, assoc a [ ...; (a,b); ...] = b if (a,b) is the leftmost binding of a in list l. Raise Not_found if there is no value associated with a in the list l. */

let assq: ('a, list(('a, 'b))) => 'b;
/* Same as List.assoc, but uses physical equality instead of structural equality to compare keys. */

let mem_assoc: ('a, list(('a, 'b))) => bool;
/* Same as List.assoc, but simply return true if a binding exists, and false if no bindings exist for the given key. */

let mem_assq: ('a, list(('a, 'b))) => bool;
/* Same as List.mem_assoc, but uses physical equality instead of structural equality to compare keys. */

let remove_assoc: ('a, list(('a, 'b))) => list(('a, 'b));
/* remove_assoc a l returns the list of pairs l without the first pair with key a, if any. Not tail-recursive. */

let remove_assq: ('a, list(('a, 'b))) => list(('a, 'b));
/* Same as List.remove_assoc, but uses physical equality instead of structural equality to compare keys. Not tail-recursive. */

let split: list(('a, 'b)) => (list('a), list('b));
/* Transform a list of pairs into a pair of lists: split [(a1,b1); ...; (an,bn)] is ([a1; ...; an], [b1; ...; bn]). Not tail-recursive. */

let combine: (list('a), list('b)) => list(('a, 'b));
/* Transform a pair of lists into a list of pairs: combine [a1; ...; an] [b1; ...; bn] is [(a1,b1); ...; (an,bn)]. Raise Invalid_argument if the two lists have different lengths. Not tail-recursive. */

let sort: (('a, 'a) => int, list('a)) => list('a);
/* Sort a list in increasing order according to a comparison function. The comparison function must return 0 if its arguments compare as equal, a positive integer if the first is greater, and a negative integer if the first is smaller (see Array.sort for a complete specification). For example, Pervasives.compare is a suitable comparison function. The resulting list is sorted in increasing order. List.sort is guaranteed to run in constant heap space (in addition to the size of the result list) and logarithmic stack space.
The current implementation uses Merge Sort. It runs in constant heap space and logarithmic stack space. */

let stable_sort: (('a, 'a) => int, list('a)) => list('a);
/* Same as List.sort, but the sorting algorithm is guaranteed to be stable (i.e. elements that compare equal are kept in their original order) .
The current implementation uses Merge Sort. It runs in constant heap space and logarithmic stack space. */

let fast_sort: (('a, 'a) => int, list('a)) => list('a);
/* Same as List.sort or List.stable_sort, whichever is faster on typical input. */

let sort_uniq: (('a, 'a) => int, list('a)) => list('a);
/* Same as List.sort, but also remove duplicates. */

let merge: (('a, 'a) => int, list('a), list('a)) => list('a);
/* Merge two lists: Assuming that l1 and l2 are sorted according to the comparison function cmp, merge cmp l1 l2 will return a sorted list containting all the elements of l1 and l2. If several elements compare equal, the elements of l1 will be before the elements of l2. Not tail-recursive (sum of the lengths of the arguments). */

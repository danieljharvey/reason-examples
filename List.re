/* first let's 'open' List, meaning we can run length(...) instead of List.length(...) for the rest of this file */
open List;

let length: list('a) => int;
/* Return the length (number of elements) of the given list. */

let ans1 = length([1,2,3,4]); /* ans1 == 4 */
let ans2 = length(["hello","world"]); /* ans2 == 2 */

let hd: list('a) => 'a;
/* Return the first element of the given list. Raise Failure "hd" if the list is empty. */

let ans3 = hd([2,3,4,5]); /* ans3 == 2 */
let ans4 = hd([]); /* Failure error - consider using an option-based version of this function instead */

let tl: list('a) => list('a);
/* Return the given list without its first element. Raise Failure "tl" if the list is empty. */

let ans5 = tl([1,2,3,4]); /* ans5 = [2,3,4] */
let ans6 = tl([]); /* Failure "tl" error - consider using an option-based version of this function instead */

let nth: (list('a), int) => 'a;
/* Return the n-th element of the given list. The first element (head of the list) is at position 0. Raise Failure "nth" if the list is too short. Raise Invalid_argument "List.nth" if n is negative. */

let ans7 = nth([1,2,3,4,5], 1); /* ans7 == 2 */
let ans8 = nth([1,2,3,4,5], 5); /* Failure "nth" error - consider using an option-based version of this function instead */
let ans9 = nth([1,2,3,4,5], -1); /* Invalid_argument "List.nth" - consider using an option-based version of this function instead */

let rev: list('a) => list('a);
/* List reversal. */

let ans10 = rev([1,2,3,4,5]); /* ans10 == [5,4,3,2,1] */
let ans11 = rev(["bed","the","shit"]); /* ans11 == ["shit","the","bed"] */

/* APPEND */
let append: (list('a), list('a)) => list('a);
/* Catenate two lists. Same function as the infix operator @. Not tail-recursive (length of the first argument). The @ operator is not tail-recursive either. */

let ans12 = append([1,2,3], [4,5,6]); /* ans12 == [1,2,3,4,5,6] */
let ans13 = append(["let's","plop","these"],["strings","together"]); /* ans13 == ["let's", "plop", "these", "strings","together"] */

let rev_append: (list('a), list('a)) => list('a);
/* List.rev_append l1 l2 reverses l1 and concatenates it to l2. This is equivalent to List.rev l1 @ l2, but rev_append is tail-recursive and more efficient. */

let ans14 = rev_append([3,2,1], [4,5,6]); /* ans14 == [1,2,3,4,5,6] */
let ans15 = rev_append(["how","this","is"], ["it","works?"]); /* ans15 == ["is","this","how","it","works?"] */

let concat: list(list('a)) => list('a);
/* Concatenate a list of lists. The elements of the argument are all concatenated together (in the same order) to give the result. Not tail-recursive (length of the argument + length of the longest sub-list). */

let ans16 = concat([["nice","and"],["tidy"],["now"]]); /* ans16 == ["nice","and","tidy","now"] */
let ans17 = concat([[1,2,3],[4],[],[5,6]]); /* ans17 == [1,2,3,4,5,6] */

let flatten: list(list('a)) => list('a);
/* Same as concat. Not tail-recursive (length of the argument + length of the longest sub-list). */
let ans18 = flatten([["nice","and"],["tidy"],["now"]]); /* ans18 == ["nice","and","tidy","now"] */
let ans19 = flatten([[1,2,3],[4],[],[5,6]]); /* ans19 == [1,2,3,4,5,6] */


let iter: ('a => unit, list('a)) => unit;
/* List.iter f [a1; ...; an] applies function f in turn to a1; ...; an. It is equivalent to begin f a1; f a2; ...; f an; () end. */
iter(str => Js.Log(str), ["hello","from","reason"]); /* no return value, runs Js.Log("hello"); Js.Log("from"); Js.Log("reason"); */

let iteri: ((int, 'a) => unit, list('a)) => unit;
/* Same as List.iter, but the function is applied to the index of the element as first argument (counting from 0), and the element itself as second argument. */
iteri((str,i) => Js.Log(string_of_int(i) ++ str), ["0hello","1from","2reason"]); /* no return value, runs Js.Log("0hello"); Js.Log("1from"); Js.Log("2reason"); Note the integer value i must be turned into a string and the ++ double add symbol for string concatenation */

let map: ('a => 'b, list('a)) => list('b);
/* List.map f [a1; ...; an] applies function f to a1, ..., an, and builds the list [f a1; ...; f an] with the results returned by f. Not tail-recursive. */
let ans20 = map(str => str ++ "!!", ["now","i'm","excited"]); /* ans20 == ["now!!","i'm!!","excited!!"]; */
/* the function to apply can be passed in too, like this... */
let addExclaims = str => str ++ "!!!!";
let ans21 = map(addExclaims, ["now","i'm","incredible","excited"]); /* ans20 == ["now!!!!","i'm!!!!","incredibly!!!!","excited!!!!"]; */



let mapi: ((int, 'a) => 'b, list('a)) => list('b);
/* Same as List.map, but the function is applied to the index of the element as first argument (counting from 0), and the element itself as second argument. Not tail-recursive. */

let rev_map: ('a => 'b, list('a)) => list('b);
/* List.rev_map f l gives the same result as List.rev (List.map f l), but is tail-recursive and more efficient. */

let fold_left: (('a, 'b) => 'a, 'a, list('b)) => 'a;
/* List.fold_left f a [b1; ...; bn] is f (... (f (f a b1) b2) ...) bn. */

let fold_right: (('a, 'b) => 'b, list('a), 'b) => 'b;
/* List.fold_right f [a1; ...; an] b is f a1 (f a2 (... (f an b) ...)). Not tail-recursive. */

let iter2: (('a, 'b) => unit, list('a), list('b)) => unit;
/* List.iter2 f [a1; ...; an] [b1; ...; bn] calls in turn f a1 b1; ...; f an bn. Raise Invalid_argument if the two lists have different lengths. */

let map2: (('a, 'b) => 'c, list('a), list('b)) => list('c);
/* List.map2 f [a1; ...; an] [b1; ...; bn] is [f a1 b1; ...; f an bn]. Raise Invalid_argument if the two lists have different lengths. Not tail-recursive. */

let rev_map2: (('a, 'b) => 'c, list('a), list('b)) => list('c);
/* List.rev_map2 f l1 l2 gives the same result as List.rev (List.map2 f l1 l2), but is tail-recursive and more efficient. */

let fold_left2: (('a, 'b, 'c) => 'a, 'a, list('b), list('c)) => 'a;
/* List.fold_left2 f a [b1; ...; bn] [c1; ...; cn] is f (... (f (f a b1 c1) b2 c2) ...) bn cn. Raise Invalid_argument if the two lists have different lengths. */

let fold_right2: (('a, 'b, 'c) => 'c, list('a), list('b), 'c) => 'c;
/* List.fold_right2 f [a1; ...; an] [b1; ...; bn] c is f a1 b1 (f a2 b2 (... (f an bn c) ...)). Raise Invalid_argument if the two lists have different lengths. Not tail-recursive. */

let for_all: ('a => bool, list('a)) => bool;
/* for_all p [a1; ...; an] checks if all elements of the list satisfy the predicate p. That is, it returns (p a1) && (p a2) && ... && (p an). */

let exists: ('a => bool, list('a)) => bool;
/* exists p [a1; ...; an] checks if at least one element of the list satisfies the predicate p. That is, it returns (p a1) || (p a2) || ... || (p an). */

let for_all2: (('a, 'b) => bool, list('a), list('b)) => bool;
/* Same as List.for_all, but for a two-argument predicate. Raise Invalid_argument if the two lists have different lengths. */

let exists2: (('a, 'b) => bool, list('a), list('b)) => bool;
/* Same as List.exists, but for a two-argument predicate. Raise Invalid_argument if the two lists have different lengths. */

let mem: ('a, list('a)) => bool;
/* mem a l is true if and only if a is equal to an element of l. */

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
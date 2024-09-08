# Tries

Tries Data Structure(multiway tree) is used in pattern making.
Tries are used in implementing spell checkers and auto-complete features

<img src="https://miro.medium.com/v2/resize:fit:1396/1*e3549k5A9oCLn-vZTxsFEA.gif">

### Operations In Tries: 

&rarr; Insertion

&rarr; Search

&rarr; Removal

## Insertion
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20220902035030/ex1.png">
2 cases: 
<li> absent :
  create it
</li>
<li> present :
  go to that node
</li>
If you are at last character of string: mark it as terminal

## Search
![image](https://github.com/user-attachments/assets/35c85efd-c0a3-4db8-917c-c30275fe7c2a)

2 cases: 
<li> present :
  go to that node, check isTerminal for last character
</li>
<li> absent :
  return
</li>

## Removal
2 cases: 
<li> present :
  go to that node, mark isTerminal as False
</li>
<li> absent :
  return
</li>

### Time complexity of insertion,search and removal:
O(L) where L is the length of string

O(1) if n>>>L

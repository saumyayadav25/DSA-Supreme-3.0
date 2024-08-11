## Let's Learn Arrays

Array: container which stores **same** type items.
Array elements must have **continuous memory**.


#### Creation of an Array
Declaration: (garbage value will be allocated by default)
```
int arr[100];
```
Initialisation:
```
int arr[5] = {10,20,30,40,50};
```
- If array size is large and elements given is less then,for example `int arr[5]={10,20};` the output array will have elements - 10,20,0,0,0

#### fill(): syntax
```
fill(starting address, ending address, value);
```

#### indexing
arr[i] or i[arr]-> value present at [base address + size*i]

#### Functions with arrays
Array is **passed by reference** inside function parameter.

## Algorithm Learnt -> Linear search
<img src="https://imgs.search.brave.com/om75SMem80EI6iMiiJGVyGVklTnsmdnV71XQsxuAWBQ/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly9maWxl/cy5wcmVwaW5zdGEu/Y29tL3dwLWNvbnRl/bnQvdXBsb2Fkcy8y/MDIyLzAxL0xpbmVh/ci1TZWFyY2gtaW4t/Qy5wbmc">

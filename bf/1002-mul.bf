,		Save input 1 in Cell 0
---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----
>,             Save input 2 in cell 1
---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

The minus convert the cell set above it to number value 
>		Move to Cell 2
++++ ++++ ++++ ++++ ++++ ++++ ++++ ++++ ++++ ++++ ++++ ++++
The plus set Cell 2 to value of 48 which is zero 0
<		loop variable input 2 cell 1 
[
	<	inner loop variable input 1 cell 0
	[
		>>+ increment cell 2 by 1
		>+ increment cell 3 by 1 inner loop count
		<<<- decrement loop variable cell 0
	]

	>>> cell 3 holds inner loop value
	To get back the value of the inner loop variable value
	[
		<<<+ reincrement cell 0
		>>>- decrement loop variable cell 3
	]
	<<-   decrement outer loop variable cell  1
]		
>.	print result of multiplication cell2

JobID: cp264-a10
Name: Cassel Robson
ID: 210507000

Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Grade_Item_ID [self-evaluation/total/marker-evaluation] Description

A10

Q1 Edge list graph data structure
Q1.1 [3/3/*] new_edgelist()                          
Q1.2 [3/3/*] add_edge_start(),add_edge_end()         
Q1.3 [3/3/*] weight_edgelist()                       

Q2 Adjacency list graph data structure
Q2.1 [3/3/*] new_graph(),clean_graph()               
Q2.2 [3/3/*] add_edge(),get_weight()                 
Q2.3 [3/3/*] display_bforder()                       
Q2.4 [3/3/*] display_dforder()                       

Q3 Graph algorithms
Q3.1 [1/3/*] mst_prim()                              
Q3.2 [1/3/*] spt_dijkstra()                          
Q3.3 [1/3/*] sp_dijkstra()                           

Total: [0/30/*]

Copy and paste the console output of your public test in the following. 
This will help markers to evaluate your program if it fails the marking tests.  

Q1 output:
C:\Users\Cassel Robson\cp264\assignments\assignment10>q1
display_edgelist():
size:4
(from to weight):(0 2 3) (2 1 4) (1 3 9) (1 4 11)
weight:27

Q2 output:
C:\Users\Cassel Robson\cp264\assignments\assignment10>q2
display_graph():
order:5
size:12
from:(to weight)
0:(1 7) (2 3)
1:(0 7) (2 4) (3 9) (4 11)
2:(0 3) (1 4) (3 10)
3:(2 10) (1 9)
4:(1 11)
display_bforder():0 1 2 3 4
display_dforder():0 2 3 1 4

Q3 output:
C:\Users\Cassel Robson\cp264\assignments\assignment10>q3
display_graph(g):
order:5
size:12
from:(to weight)
0:(1 7) (2 3)
1:(0 7) (2 4) (3 9) (4 11)
2:(0 3) (1 4) (3 10)
3:(2 10) (1 9)
4:(1 11)

mst_prim(g, 0):
size:2
(from to weight):(0 2 3) (2 1 4)
mst weight:7

spt_dijkstra():size:2
(from to weight):(0 2 3) (0 1 7)
spt weight:10
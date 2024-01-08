JobID: cp264-a6
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


Q1 Queue data structure
Q1.1 [3/3/*] enqueue()                               
Q1.2 [3/3/*] dequeue()                               
Q1.3 [2/2/*] clean_queue()                           

Q2 Stack data structure
Q2.1 [3/3/*] push()                                  
Q2.2 [3/3/*] pop()                                   
Q2.3 [2/2/*] clean_stack()                           

Q3 Postfix and infix expression evaluation
Q3.1 [0/6/*] infix_to_postfix()                      
Q3.2 [5/5/*] evaluate_postfix()                      
Q3.3 [3/3/*] evaluate_infix()                        

Total: [30/30/*]

Copy and paste the console output of your public test in the following. 
This will help markers to evaluate your program if it fails the marking tests.  

Q1 output:
C:\Users\Cassel Robson\cp264\assignments\a6>q1
enqueue:10-((3*4)+8)/4
display queue:10 - ( ( 3 * 4 ) + 8 ) / 4
queue length:13
dequeue:10 - ( ( 3 * 4 ) + 8 ) / 4
queue-length:0

Q2 output:
C:\Users\Cassel Robson\cp264\assignments\a6>q2
str:12 34 56 78 90 + - * /
display stack:/ * + 90 78 56 34 12
stack height:8
pop:/ * + 90 78 56 34 12
stack-height:0

Q3 output:
C:\Users\Cassel Robson\cp264\assignments\a6>q3
infix expression:10-((3*4)+8)/4
postfix expression:10 3 4 * 8 + 4 / -
postfix evaluation:5
infix evaluation:5

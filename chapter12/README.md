Chapter 12 Practice problems

1. Take a small program that you've written before, perhaps as one of the practice problems from earlier in the book. Look for all
of the variables, and imagine each variable as having some memory associated with it. Try drawing out a box diagram like the ones
I've used that would show each variable associated with some memory. Think of how you might represent a series of variables that are not part of a single array—but that are lined up in memory one after another.
2. Think about how many slots of memory are needed for this program:

int main ()
{
    int i;
    int votes[ 10 ];
}

Is there anything you can say for sure about the positions in memory of the variables votes[ 0 ] , votes[ 9 ] , and i ? (Hint: you might not be able to know where i is, but you do know where it is not.) Try drawing out the possible configurations of memory for this program.
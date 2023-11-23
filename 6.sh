i=1                          # Initialize a variable 'i' with the value 1.
while [ $i -le 10 ]           # Start a while loop that continues while 'i' is less than or equal to 10.
do                           # Begin the loop.
  echo "$i"                  # Print the value of 'i'.
  i=$(expr $i + 1)           # Update the value of 'i' by incrementing it.
done                         # End the loop.

echo "Enter the number"
read n
c=`expr $n % 2`
if [ $c -eq 0 ]
then echo "Number is even"
else
echo "Number is odd"
fi 

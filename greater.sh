echo "Enter the first number"
read a
echo "Enter the second number"
read b
echo "Enter the third number"
read c
if [ $a -gt $b ]
then if [ $a -gt $c ]
then echo "first number is greater"
else
echo "third number is greater"
fi
else
if [ $b -gt $c ]
then echo "second number is greater"
else
echo "third number is greater"
fi
fi 

echo "Enter the temperature in Fahrenheit"
read h
c=`expr \( $h - 32 \) \* 5 / 9`
echo "Temperature in Centigrade is c=$c" 

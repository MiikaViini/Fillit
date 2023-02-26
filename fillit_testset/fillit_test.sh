#!/bin/bash
clear
RED='\033[4;31m'
RED='\033[1;7;31m'
GREEN='\033[4;32m'
YELLOW='\033[1;7;33m'
ENDCOLOR='\033[0m'


NORM=$(diff results/norminette results/norminette_answer)
#
# reading fillits results to output_invalid
#
 ../fillit 123 2>&1 >results/output_invalid
for file in testfiles/invalid_files/*; do
	clear
	printf "${file}:\n"
	printf "\n"
	cat "$file"
	printf "\n"
	printf "Output of your fillit:\n\n"
	.././fillit "$file"
	.././fillit "$file" 2>&1 >>results/output_invalid
	read
done

DIFF_INV=$(diff results/output_invalid results/answers_invalid)
clear
if [ "$DIFF_INV"  != "" ]
then
	printf "${RED}Failed invalid tests ${ENDCOLOR}\n"
	printf "${DIFF_INV}\n"
fi

if [ "$DIFF_INV" == "" ]
then
	printf "${GREEN}Passed invalid tests${ENDCOLOR}\n"
	rm results/output_invalid
fi
read
#
# reading fillits results to output_valid
#

for file in testfiles/valid_files/*; do
	clear
	printf "${file}:\n"
	printf "\n"
	cat "$file"
	printf "\n"
	printf "Output of your fillit:\n\n"
	.././fillit "$file"
	.././fillit "$file" 2>&1 >>results/output_valid
	read
done
DIFF_VAL=$(diff results/output_valid results/answers_valid)

norminette ..| grep Error > results/norminette

clear

if [ "$DIFF_VAL"  != "" ]
then
	printf "${RED}Failed valid tests ${ENDCOLOR}\n"
	printf "${DIFF_VAL}\n"
fi

if [ "$DIFF_VAL" == "" ]
then
	printf "${GREEN}Passed valid tests${ENDCOLOR}\n"
fi

read

clear

if [ "$NORM"  != "" ]
then
	printf "${RED}Failed Norm tests ${ENDCOLOR}\n"
	cat results/norminette
	read
fi

if [ "$NORM" == "" ]
then
	printf "${GREEN}Passed Norm tests${ENDCOLOR}\n"
	read
fi

printf "${YELLOW}Usage test${ENDCOLOR}\n"
echo './fillit'
../fillit
echo './fillit 123 123'
../fillit 123 123
read

printf "\n"
printf "${YELLOW}Evaluation form speedtest 1${ENDCOLOR}\n"
printf "\n"
{ time .././fillit testfiles/valid_files/test1; }

printf "\n"
read
printf "${YELLOW}Evaluation form speedtest 7${ENDCOLOR}\n"
printf "\n"
{ time .././fillit testfiles/valid_files/test7; }
read

clear
printf "${RED}END OF TEST${ENDCOLOR}\n"
# rm results/output_valid
rm results/norminette
read





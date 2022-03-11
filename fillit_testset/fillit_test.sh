#!/bin/bash
clear
RED='\033[4;31m'
RED='\033[1;7;31m'
GREEN='\033[4;32m'
YELLOW='\033[1;7;33m'
ENDCOLOR='\033[0m'
DIFF_INV=$(diff results/output_invalid results/answers_invalid)
DIFF_VAL=$(diff results/output_valid results/answers_valid)
NORM=$(diff results/norminette results/norminette_answer)

.././fillit testfiles/invalid_files/invalid_file 2>&1 >results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece2 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece3 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece4 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece5 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece6 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece7 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece8 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece9 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_piece10 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_pieces11 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_pieces12 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_pieces13 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_pieces14 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_pieces15 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_pieces16 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_pieces17 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_pieces18 2>&1 >>results/output_invalid
.././fillit testfiles/invalid_files/invalid_toomany 2>&1 >>results/output_invalid

printf "\n"
if [ "$DIFF_INV"  != "" ]
then
	printf "${RED}Failed invalid tests ${ENDCOLOR}\n"
	printf "${DIFF_INV}\n"
fi

if [ "$DIFF_INV" == "" ]
then
	printf "${GREEN}Passed invalid tests${ENDCOLOR}\n"
fi
read
.././fillit testfiles/valid_files/test_i 2>&1 >results/output_valid
.././fillit testfiles/valid_files/test_L 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_L2 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_L3 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_L4 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_o 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_s 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_s2 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_s3 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_s4 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_subject 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_t 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_t2 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_t3 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test_t4 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test-easy 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test1 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/test7 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/testI 2>&1 >>results/output_valid
.././fillit testfiles/valid_files/speedster 2>&1 >>results/output_valid

norminette ..| grep Error > results/norminette


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
if [ "$NORM"  != "" ]
then
	printf "${RED}Failed Norm tests ${ENDCOLOR}\n"
fi

if [ "$NORM" == "" ]
then
	printf "${GREEN}Passed Norm tests${ENDCOLOR}\n"
fi
read
printf "\n"
printf "${YELLOW}Evaluation form test1${ENDCOLOR}\n"
printf "\n"
{ time .././fillit testfiles/valid_files/test1; }

printf "\n"
read
printf "${YELLOW}Evaluation form test7${ENDCOLOR}\n"
printf "\n"
{ time .././fillit testfiles/valid_files/test7; }
read

printf "${RED}END OF TEST${ENDCOLOR}\n"
#rm results/output



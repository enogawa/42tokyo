#!/bin/sh

make all clean -sC ../


printf "~~~~~~~~~~~~~~~test start~~~~~~~~~~~~~~~~~~~~\n\n\n"
printf "=============================================\n"
printf "               invalid case                  \n"
printf "=============================================\n\n"

printf "\ne_2gata.ber\t\t"
../so_long invalid/e_2gata.ber

printf "\ne_gatagata.ber\t\t"
../so_long invalid/e_gatagata.ber

printf "\ne_h_wall.ber\t\t"
../so_long invalid/e_h_wall.ber

printf "\ne_lost_c_map.ber\t"
../so_long invalid/e_lost_c_map.ber

printf "\ne_lost_e_map.ber\t"
../so_long invalid/e_lost_e_map.ber

printf "\ne_lost_p_map.ber\t"
../so_long invalid/e_lost_p_map.ber

printf "\ne_w_wall.ber\t\t"
../so_long invalid/e_w_wall.ber

printf "\nerror_line.ber\t\t"
../so_long invalid/error_line.ber

printf "\nerror_line2.ber\t\t"
../so_long invalid/error_line2.ber

printf "\nextra_params.ber\t"
../so_long invalid/extra_params.ber

printf "\nextra_player.ber\t"
../so_long invalid/extra_player.ber

printf "\nno_exit.ber\t\t"
../so_long invalid/no_exit.ber

printf "\nno_item.ber\t\t"
../so_long invalid/no_item.ber

printf "\nno_player.ber\t\t"
../so_long invalid/no_player.ber

printf "\nno_wall.ber\t\t"
../so_long invalid/no_wall.ber

printf "\nnot_square.ber\t\t"
../so_long invalid/not_square.ber

printf "\nnotber\t\t\t"
../so_long invalid/notber

printf "\nno_map.ber\t\t"
../so_long invalid/no_map.ber

printf "\nno file\t\t\t"
../so_long invalid/no_file.ber

printf "\n\n=============================================\n"
printf "                valid case!                \n"
printf "=============================================\n\n"

printf "bigmap.ber -----------------------------\n"
../so_long valid/bigmap.ber 
printf "c_map.ber -----------------------------\n"
../so_long valid/c_map.ber 
printf "no_nl.ber -----------------------------\n"
../so_long valid/no_nl.ber 
printf "simple.ber -----------------------------\n"
../so_long valid/simple.ber 
printf "test.ber -----------------------------\n"
../so_long valid/test.ber 

printf "\n~~~~~~~~~~~~~~~TEST END~~~~~~~~~~~~~~~~~~~~\n\n\n"


# make fclean -sC ../

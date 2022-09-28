#!/bin/sh

make all clean -C ../


printf "~~~~~~~~~~~~~~~test start~~~~~~~~~~~~~~~~~~~~\n\n\n"
printf "=============================================\n"
printf "                 valid case                  \n"
printf "=============================================\n\n"

printf "e_2gata.ber\t\t"
../so_long invalid/e_2gata.ber

printf "e_gatagata.ber\t\t"
../so_long invalid/e_gatagata.ber

printf "e_h_wall.ber\t\t"
../so_long invalid/e_h_wall.ber

printf "e_lost_c_map.ber\t"
../so_long invalid/e_lost_c_map.ber

printf "e_lost_e_map.ber\t"
../so_long invalid/e_lost_e_map.ber

printf "e_lost_p_map.ber\t"
../so_long invalid/e_lost_p_map.ber

printf "e_w_wall.ber\t\t"
../so_long invalid/e_w_wall.ber

printf "error_line.ber\t\t"
../so_long invalid/error_line.ber

printf "error_line2.ber\t\t"
../so_long invalid/error_line2.ber

printf "extra_params.ber\t"
../so_long invalid/extra_params.ber

printf "extra_player.ber\t"
../so_long invalid/extra_player.ber

printf "no_exit.ber\t\t"
../so_long invalid/no_exit.ber

printf "no_item.ber\t\t"
../so_long invalid/no_item.ber

printf "no_player.ber\t\t"
../so_long invalid/no_player.ber

printf "no_wall.ber\t\t"
../so_long invalid/no_wall.ber

printf "not_square.ber\t\t"
../so_long invalid/not_square.ber

printf "notber\t\t\t"
../so_long invalid/notber

printf "no_map.ber\t\t"
../so_long invalid/no_map.ber

printf "no file\t\t\t"
../so_long invalid/no_file.ber

printf "\n\n=============================================\n"
printf "                valid case!                \n"
printf "=============================================\n\n"

printf "bigmap.ber -----------------------------\n"
../so_long valid/bigmap.ber | grep "total leaked bytes." && printf "\n"
printf "c_map.ber -----------------------------\n"
../so_long valid/c_map.ber | grep "total leaked bytes." && printf "\n"
printf "no_nl.ber -----------------------------\n"
../so_long valid/no_nl.ber | grep "total leaked bytes." && printf "\n"
printf "simple.ber -----------------------------\n"
../so_long valid/simple.ber | grep "total leaked bytes." && printf "\n"
printf "test.ber -----------------------------\n"
../so_long valid/test.ber | grep "total leaked bytes." && printf "\n"

printf "\n~~~~~~~~~~~~~~~TEST END~~~~~~~~~~~~~~~~~~~~\n\n\n"


make fclean -C ../
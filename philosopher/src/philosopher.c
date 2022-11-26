#include "./../philosopher.h"

int	argcheck(argc, argv)
{

}

void	error_return(char *str)
{
	write(1, &str, ft_strlen(str));
	write(1, '\n', 1);
}

int	main(int argc, char **argv)
{
	// 構造体
	t_date	*date;
	// memset 0でイニシャライズ
	memset(memset, 0, sizeof(t_date));
	// argcheck 5 6 数じゃないとout
	if (argcheck(argc, argv))
	{
		error_return("invlid arguments");
		return (1);
	}
	//  ミューテックス
	// 実行　main
		// スレッドの作成
			// 哲学者には行動を
			// 監視スレには　監視の行動を
	// 終了処置
}
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 15:58:37 by acharras          #+#    #+#              #
#    Updated: 2020/02/28 18:29:28 by acharras         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #



SRC =	ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_putchar.c\
		ft_strjoin_f_s1.c\
		ft_strcpy.c\
		get_next_line.c\
		ft_memdel.c\
		ft_int_len.c\
		ft_itoa_base.c\
		ft_strjoin_free.c\
		ft_strchr_set.c\
		ft_strcmp.c\
		ft_strjoin_f_s2.c\
		ft_rmchr.c\
		ft_strcheck_chr.c

OBJ = $(SRC:.c=.o)

HEADERS =	libft.h

NAME =	libft.a

CC =	cc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1

RM =	rm -rf


all :	$(NAME)


$(NAME) :	$(OBJ) $(HEADERS)
				@ar rc $(NAME) $(OBJ)
			@echo "\033[38;2;153;102;255;1m######################################"
			@echo "\033[38;2;153;102;255;1m#\033[38;2;0;204;0;1m\tCompiling $(NAME)...   \033[38;2;153;102;255;1m\t     #\n#\033[38;2;0;204;0;1m\t\tDone\t\t     \033[0m\033[38;2;153;102;255;1m#"
			@echo "\033[38;2;153;102;255;1m######################################\033[0m"


%.o: %.c $(HEADERS)
			@$(CC) $(CFLAGS) -o $@ -c $<
			@echo "\033[38;2;255;204;0;1mCompiling object $@...\nDone\033[0m"


clean :
			@$(RM) -f $(OBJ)
			@echo "\033[38;2;255;51;0;1mDeleting objects file...\nDone"


fclean :	clean
				@rm -f $(NAME)
				@echo "Deleting $(NAME)...\nDone\033[0m"

				
re :	fclean all

strange : all

	@echo "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''''''''''''''''...........''''''''''''''''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''''''''''.....................'''''''''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''''''''.......'''       '''......'''''''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''''''.....'                   '....'''''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''''....'                        '....'''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''....'                             ...''''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''...'                                '...''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''..'                                   '...'''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''...'              ',;i***i;,.            '...''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''...            .izxWWWWWWW@@@@Mz;'         ',..'''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''...          ';nWWMMWWW@@@@@@@@@@@W#.        '....'''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''..         'ixWMxMW@@@@@@@@@@@#@#@@#@*          '...'''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''..'        ,xWMnMWW@@@@@@@WWWWWW@@@###@z'         '...''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''..'        *WWnnMMW@@@WWWWWWWWWWWWWW@#####           ...'''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''...       'zWMzzxW@@WWWWWWWWW@@@@@@WW@@@##@;           ...''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''..       'zWMznW@@WWMMWWWW@@@@@@@@@@@@@W@##x            ...'''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''..'       #WWnM@@WWMxMWW@@@@WWWWWWWW@@@#@@##@xz*.         ..'''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''..       *WWMW@@MxxMWW@WWWWWWWWWWWWWW@@@@#####@@W#'       '..''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''..'      ,WWWW@@MnxW@@@WWWMxMMWWWWWWWWWW@@@####@@@@x.       '..'''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''..      'nWW@@@MxW@@@WWMnnnxMWWWWWWWWWWWWW@@#@@@@W@@M.       '..''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''..'      iWW@@@WMW@@@WMxxxnMMMWWWWWWW@@@@WWW@#@@@@@@@@n'       ..''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''..      'MW@@@WWW@@@WMMWn#nnxWWWW@@@@@@@@@@@W@#@@@WWW@@z       '..'''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''..'      *WW@@WWW@@@WWWMnnnnMWW@@@@@@@@@@@@@@@@#@@@@@@@@@+       ..'''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''..      'xW@#@WW@@@WWWWMMxMW@@@@@@WWWW@@@@#######@##@@@@@W,      ..'''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''..      iM@@@WW@@@WWWWWWWW@@@@@WWWWWWWW@@@@@######@@@@@@@@z      '..''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''..'      zW@#@W@@@WWWWWWWW@@@@WMWWWWWWWWW@@@@@#####@@WWWWW@@'      ..''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''..      ,W@@@@@@@WWWWWWW@@@@WWMMWWWWWW@@@@@@@@@###@@@WWWWW@@;      '..'''''''''''''''''''''"
	@echo "''''''''''''''''''''''''..'      +W@#@@#@@WWWWWW@@#@@WMxWWW@@@@@@@@@@@@@@##@@@WWMMWW@x'      ..'''''''''''''''''''''"
	@echo "''''''''''''''''''''''''..       xW@@@@#WWWWWWW@@@@WWWxxW@@@WWWWWWW@#@@@@##@@@@WWxMW@@i      '..''''''''''''''''''''"
	@echo "'''''''''''''''''''''''..'      ,W@#@@#@WWWWWW@@#@@WWMxW@@WWWWWWWWWW@@#@@##@@@@@WWMMW@W'      ..''''''''''''''''''''"
	@echo "'''''''''''''''''''''''..       z@@#@@#WWWWWW@@##@WWWMW@@WWWWWW@@@@@@@@#@##@@@@@@@@WW@@*      ..''''''''''''''''''''"
	@echo "''''''''''''''''''''''..'      .@@@@@@#W@WWW@@@#@WWWWW@@WWMWW@@@@@@#@@@@###@@@WWWW@@@@@x      '..'''''''''''''''''''"
	@echo "''''''''''''''''''''''..       z@@#@@@#MWWW@W@##@WWWWW@@WMMMW@@@@@@@@#@@###@@@WWWMW@@@@@.      ..'''''''''''''''''''"
	@echo "'''''''''''''''''''''..'      ,W@@#@@@@WWWWW@###@WWWW@@WMnM@##@#####@@#@###@@@@WWMxW@@@@i      ..'''''''''''''''''''"
	@echo "'''''''''''''''''''''.,       z@@@@@@#@WWWWW@@@@@WWWW@@WxW@@@@@@@@###@####@@@@WWWWWnW@#@#      ..'''''''''''''''''''"
	@echo "''''''''''''''''''''..'      ,W@##@@@#@WWWW@@@@@@WWW@@@W@@@@@@@@@@@@##@##@@@@@@WMMWxx@#@x      '.'''''''''''''''''''"
	@echo "'''''''''''''''''''..'       #@@#@@@@#@W@WW@@@@@@@WW@@@@@@@@@@@@@@@@@@@@n+++zW@@WxxMnW@@W'     '..''''''''''''''''''"
	@echo "'''''''''''''''''''..       'W@@@@@@##WM@WMnxW@@W@WWxn@WM@z*Mn*zM*;n#xz;....,;n#@@MznM@@@.     '..''''''''''''''''''"
	@echo "''''''''''''''''''..'       iW@@@@@#@@@x@W+:,:zz:MW@i;@z,:,.,...,...,;.......,:x@#@x#x@#@:      ..''''''''''''''''''"
	@echo "''''''''''''''''''..        #WWW@#@@@@Wx@M;,.....*WW:,W+....''''..............,i@@@@nxW#@i      ..''''''''''''''''''"
	@echo "''''''''''''''''''..      .*MW@@@#@@@@nnWn,.......xW:.##...'''''''''''''''.....,W@@@@xW@@#      ..''''''''''''''''''"
	@echo "''''''''''''''''''..       'x@@@@@@@@@#nx#,..''''';x:.,n...''''''''''''''''....,x@@@@WW@@n      ..''''''''''''''''''"
	@echo "''''''''''''''''''..'      'M@@@@@WWW@nzz+..'''''''+*..::.''''''''''''''''''...,z@@@@@@@#M      '..'''''''''''''''''"
	@echo "'''''''''''''''''''..      'M@@@@@WMW@M*n+....'''''.+....'''''''''''''''''.''..,+@@W@@#@@W'      ..'''''''''''''''''"
	@echo "'''''''''''''''''''..'     'M@@@@WWWW@W;zz*nWWx*,'''..''''''''''''''''',+MWMzi,,;@@WW@@@@@:      ...''''''''''''''''"
	@echo "'''''''''''''''''''...      n@@M@WWMW@@;;MxW@@WWWz;'''''''''''''''''.inWWW@@Wn*,:W@@@@@@##z      '..''''''''''''''''"
	@echo "''''''''''''''''''''..      *W@i@WWW@@W:,*i,*nWWWWWxi.''''''''''''.*xWWW@Wni....:z#xWMnx@@M'      '..'''''''''''''''"
	@echo "''''''''''''''''''''..      .WW'MWW@@Wz:,.i..',+MWWWWx*.''''''''.+MWWW@x*.'''...:n:,,::#*@@;       '..''''''''''''''"
	@echo "''''''''''''''''''''..'      nW'+W@M#i#:,.....'..ixWWMMM+'''''.#MWMWWn;.'''''...:x#,.:z: *@x'       ..''''''''''''''"
	@echo "'''''''''''''''''''''..      :@.:+:,.:#:,..........ixWMMM'''''.WWWWx;....'''....:z*z#zn'  ;W+       '.''''''''''''''"
	@echo "'''''''''''''''''''''..       #i'#,..in:,....:*##*:..izMz''''''xMz;..:+z#*:.....,z;,:i+    .#i      '.''''''''''''''"
	@echo "'''''''''''''''''''''..'      '+ **;+zz;;i#x@#####@z,..,,'''''',...:n@#@###Wx#;::x+:;z.      '      '.''''''''''''''"
	@echo "''''''''''''''''''''''..       '..x#;;n#@##@@WMxxxMWM:..''''''''..;WWMxxxMW@###@iM@@W.              '.''''''''''''''"
	@echo "''''''''''''''''''''''..'         +:iM@*Mx+:xnz###zxMM,.''''''''.:WMnz##*zxz:+Mn:WW@i               ..''''''''''''''"
	@echo "'''''''''''''''''''''''..'        ;M@@@#ii''x+i#M.:#n*#.'''''''',#+n+*x# ;zn'.*:i@Wn*              '..''''''''''''''"
	@echo "''''''''''''''''''''''''..        *z@@@n,i'.x*iM@i:*zi.:'''''''':'*#i+#W*i#x'.i,+@M::,             ..'''''''''''''''"
	@echo "''''''''''''''''''''''''...       *:n@@M,,.'xi;W##**z;'.''''''''''*#i+##Mi#n',.,nW;.,;           '..''''''''''''''''"
	@echo "'''''''''''''''''''''''''...      *.:x@M:,.'zi,##Mi*n,''''''''''''i#::M@#i#z'..:W*.',;      ''''...'''''''''''''''''"
	@echo "''''''''''''''''''''''''''..      i..:MW:,.'++:.;;i+n''''''''''''',zi,,;;iz*..,:z,''i.     ',,....''''''''''''''''''"
	@echo "''''''''''''''''''''''''''..      .*',i@:,..,z;,,:iz+'''........'''#+:,,:+n,..,;i.''+      '...'''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''..'      *,.,n;,...++;;i#n.'............',z*;;*n*,.,,*:.'i,      ..'''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''..      '+..**,,,,;nz#zn,'...............;z##xz;,.,:+,.:i       ..'''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''..       .+,:+,,,,,,i*+;,........,.......,;+*;,,,,,:#.;i       '..'''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''..'       '*;#:,,,,,,,,,,......,.,,.....,,,,,,,,,,,;+i;        ..''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''..'        :z:,,,,,,,,,,,.....,,,,....,,,,,,,,,,,:i+.        ...''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''..,         i;,,,,,,,,,,,,............,,,,,,,,,,,:+'        ',..''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''...         **:,,,,,,,,,,,,;iiiiiiii;,.,,,,,,,,,,:n*'        ...''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''..        .zMx:,,,,,,,,,,#MWWMxxxxMWWM+.,,,,,,,,:iWMn.        ..''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''..'       ,xxMW*,,.......#WMz;......inMW+.......,:nMxxx:       '..'''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''......       :xxxxMM;,......;WMz:i.,*i:**.nWW:.....,:#MMxxxx;       ..'''''''''''''''''''''''"
	@echo "'''''''''''''''''''''.......'      ,xxxxxxMMi,.....nWW#.:**::i:..zWWz....,:zMMxxxxnx:      '..''''''''''''''''''''''"
	@echo "''''''''''''''''''.....''         'nnnxxxxxMWz:,..*WWWM:..iWW;.,;WWWWi.,,*MMMxxxxnnnn'      ..''''''''''''''''''''''"
	@echo "''''''''''''''''.....             ixnnnnnnxxMMM#::WWWWWMi,iWW;,iMWWWWM:inWMxxxxnnnnnn*      '..'''''''''''''''''''''"
	@echo "'''''''''''''''...'               znnnnnnnxxxxMMMW@WWWWWWWWWWWWWWWWWW@WWMMxxnnnxnnnnnx'     ',.'''''''''''''''''''''"
	@echo "'''''''''''''...'                ,nnnxxxxxxxxxxxMM@W@@WWWWWWWWWWWW@W@@MMxxxxxxxxxxxxnx:      ...''''''''''''''''''''"
	@echo "''''''''''''...'                 inxxMMMMMxxxxxxMM@xnxW@@WWWWW@@WMxxWWMMxxxxxxMMMMMxxx+       ...'''''''''''''''''''"
	@echo "'''''''''''...             ''''''+xMx#*#@WWMMxxM#MWW#+zxW@@@@@@Wzz#WMWM#MxxMMWM*i*#xMxz        ..'''''''''''''''''''"
	@echo "''''''''''..'          ''.,:;;;;:#n+.''nMMMWWMMM+nWWMii*WWWWWWWziinWMWx+xMMWWMW+   ';xx        '..''''''''''''''''''"
	@echo "'''''''''..'         '.,;;iii;iii#*i;:iMxMM@WWWMWWWMMz;;zMMWWMMi;*WMMWWWMWW@MMMW#    ,x'        ..''''''''''''''''''"
	@echo "''''''''..'        '.,;ii;;;i;;;;+;;;i#znxWWMMMWMMMMMM*;iWMWMMz;;xMMMWxMWMMM@MMMM#    *','      ...'''''''''''''''''"
	@echo "'''''''..'        ':ii;;;;;:;;::,::::;nzznMMxxxMMMxxMxn;:zMWMWi:+xMMMMMMxxxxMWMMMM#   ';i+       ...''''''''''''''''"
	@echo "'''''''..       '.:i;;::;;;;;;;;;;::;#nzznznxxxxMxMz*;*#:iWWMx;;zii+nMMWxnnnxxWMMxM+  ,i'*        ...'''''''''''''''"
	@echo "''''''..       '.;i;:::;;:,,,,,,,,,,;znnxzzzznxMM#i;;;i#*;xWW+;#*;;;;i#WxnnnnxxWMMxW*.+..#'        ..'''''''''''''''"
	@echo "'''''..'      '.;i;;:;;,,,::;;;;;;::;xnnnzzz#znMzi;;;izMx;+@WiiWx+;;;;iWxnnnnnxxWMxxW+..*:+'        ..''''''''''''''"
	@echo "'''''..      '.;i;;:;:,,:;;;;::::;;;+nxxnzzzzzzMzii+nxxxW##@M+nMMMMz+iiWxnnnnnnxM@M+:..,*.#+        '.''''''''''''''"
	@echo "''''..'      .;i;,:;,::;;:,,,::::,;:zznnnzzzzzznnzxxnxxMMz*ii+nWMxxxxxnWxnnnnnnxMx*',*,*,,**'        ..'''''''''''''"
	@echo "''''..      ':i;,,;,:;;::;;;::.,;;:ixxnzzzzzzzznxxnnnnMz*+nMnzi*xMxnnnxWxnnnnnnxxz#'',**:+.+,i.      ..'''''''''''''"
	@echo "'''..'      .i;;;:,:;;,,;,,:::::..,*xnnzzzzzzzznnxnnnx#**M#M*xzi#zMnnnxWWxxnnnnxx#x#**,.+*+#i,*      ..'''''''''''''"
	@echo "'''..      ':;;::::;;,:;;:,,::;;,.:znzznzzznzznnznnnM+z;zxnznzx;+z#xnnxW@WMxnxxxx+*z:....;,''i:      ..'''''''''''''"
	@echo "'''.'      ,i;;;:,;;,:::..;;::,,:;*xnnnznzzznnnnzznM#nz;nxxx+xxi*xznxnnMWMWMxxxxxzi+#,.''''.*:       ..'''''''''''''"
	@echo "''..'     ';i;:;,:;,:,'::::,,.''.;nzzznnznzznnznzznnx+z;#WMMz#n;+z#MnnnM@MMWWxxxxxzi+#,..,##'       '..'''''''''''''"
	@echo "''..      .i;;;::;:,;.,;:,.:;:;::#nnzzzzznnznnznzzznxMziiMMxMM+;+nMnnxxx@MMMMWMxxxxx++nznWMM.       .,.'''''''''''''"
	@echo "''..      ,i;:;::;,:;:;:.',:.,::#xznnzznzznnzzznzzznnxWn**nxn+i+xWxxxxxxWMMMMMWWMxxxMxMWMMMMn'       ..'''''''''''''"
	@echo "'..'     ':;;:;:;;:;:.:,':,''::*#++#nnzzznnnzznnnzznxxMWWn+**#xWWMxxMMMMWWMMxxMMWWWWWWMMxxxxW#       '..''''''''''''"
	@echo "'..'     ':;::::;:;..;:,,;:;i+#z##+i*#zznnznzzxnxnzxWWWWWW@@@@WW@@W@@WM@W@WMxxxMMMMMMMxxxxxxxWi       '..'''''''''''"
	@echo "'..'     .;;::::;,;:,;::;:++**ii;i+z++#zxnznzznznzzx#MWMMMMMMMnzMMMMMn*WMW@MxxxxMMMMMMxxxxxxxxW,       ...''''''''''"
	@echo "'..'     .;;:;::;,;,.;,,,:*+*;;ii**;z#+nnzznznzzzzzn;nxxnnnnxx#*Mnnxxn:WxM@MxxxxMMMMMxxxxnnxxxMx'       ..''''''''''"
	@echo "'..      .i;:;::;,;:::',,;i:+*:,;ii*i#nxzznznnzzn#zz;xxnnnnnnx#*MxxxMW#WWW@MxxxxxMMxxxxxxnnnxxxMz       '..'''''''''"
	@echo "'..      ,i;;;::;,,,;,'::,i++:,,;i;i;*Mx#znznnzznznz+MMMMMMMMWxnWW@@WxM@@W@WxxxxxxMxxxxxxnnnnxxxWi       ...''''''''"
	@echo "'..      .i;:;:;;:,.;,':;:+++++:;i:i;#xzzzznnnzznxzzMWWWW@MWWWMxWWWznWW+WMWWMxxxxxxxxxxxxxnnnnxxxW.       ..''''''''"
	@echo "'..'     .i;;i:;;,::,;.,,+i+*#*+;iii*nzznnznnzzzxnzzxxxxxMiMxMn+WMWx@@@MWW@@Mxxxxxxxxxxxxxxnnnnxxxx'      '..'''''''"
	@echo "'..'     .;;;;:;;,;:.:::+::#i+i+*ii;nzz#zzznnzzzxnzxMMMMMW#WMWWx@W@x@@@MWMM@MxxxxxxxxxxxxxxnnnnnxxM*       ..'''''''"
	@echo "'..'     ':;::;:;:;:,:::;++i##i**i;#znz#znznnzzznzzxWWWWWWWWWWWMMMWM#WM+WxMWWxxxxnxxxxxxxxxxnnnnxxxW.      '..''''''"
	@echo "''.'     ':;;:i:;;;:,;;,':;:+zzn;,#nnn#zzznnnnnnnzznxxnnnnnnnnnnnnxWMMM@MMWW@Mxxxnnxxxxxxxxxnnnnnxxxn       ..''''''"
	@echo "''..     ',i;;;:;;:;;,,;''::xnn*:#nnnz#zzzxnnnnnnzzxxxxxnnnnnnnxxMWW@@M@@@WWWMxxxxnnxxxxxxxxxnnnnnxxMi      '..'''''"
	@echo "''..      .i;;;;;;:,;::i:..*znz+#zzz##znznnznxnnnnnWWWWWWWMMWWW@WW@WWWWWWWMMMWxxxxnnnxxxxxxxxxnnnnxxxx'      ..'''''"
	@echo "''..'     ';;;:;:;;,:,.:;;;nzxxxnzz#z#nnznnnnnnnnzxMMMMMMMMMW@MMMMWMxMW@WWMxxWMxxxnnnnxxxxxxxxnnnnnxxx*      '..''''"
	@echo "''..'      ,i;;;;:;;,;..:.#zzzzzzz#zzzzzzzznnzzzzzxxxxxxxxxxMWMxxxWxxx@W@WWxxMWxxxxnnnnxxxxxxxxnnnnxxnx'      ..''''"
	@echo "'''..      ':;;:;;;;;:;,,;nznzzzznzz#zznzzznzzzzznxnnnnnnxxxxWWxxxMMnn@MW@WMxxWMxxxnnnznxxxxxxxnnnnnxxn*      '..'''"
	@echo "'''..'      .i;;:i:;;;::;#zznzzzzzz+#znzzznnzzzzzxnnnzznnnxxxM@MxxMWnn@MMW@WxxxWxxxxnnnznxxxxxxxnnnnxxnx       ..'''"
	@echo "''''..      ':i;:;;;;;;:+###zznnz#+#zzzzznnzzzzznxnnzzznnxxxxW@WxxxWnnWMMx@@MxxMMxxxnnnnnxxxxxxxxnnnxxxx:      ..'''"
	@echo "''''..'      .;i;;;;::;iz#znzzz#zz+zzzzzzzzzzzzzxxnnzzznnxxxM@WWxxxMxnWWWWWWWxxxWMxxxnnnnnxxxxxxxxnnxxxn#      '..''"
	@echo "'''''..      ',;;;;::;;z###zzzzzz####zzzzzzzzzznxxnnzzznnxxxM@WWMxxMMnx@W@WxxMxxxWxxxnnnnxxxxxxxxxxnxxxnx'      ..''"
	@echo "'''''..'      ',;;;;::###zz#zz######zzzzzzzzzznxxxnnnznnnxxMWWMMWxxxWnnMMxnnnMMxxMWxxxnnnnxxxxxxxxxxxxxxz;      ..''"
	@echo "''''''..       ',;i;;+#z#zzzzzzz+##z#zzznzzzznxxxxnnnnnnnxxM@MMxMWxxMMnnnnnnnnWxxxMMxxnnnnxxxxxxxxxxxxxx##      ..''"
	@echo "''''''...       '.:i*##zzzzzzz######zzzzzzzznxxxxxxnnnnnxxxM@@@@@@MxMWnxnnnxMWMMxxxMMxxnnnnxxxxxxxxxxxxx#n      '.''"
	@echo "'''''''..'        'i#+#zzzzznz####zzzzzzzznxxxxxxxxxxxxxxxMW@WWW@@@MxWMxMWWMxxxxMMMxMMxxnnnnxxxxxxMMxnnnxx'     '.''"
	@echo "''''''''.,        ,n+z##zzzzzz####zzzzzznxxxxxxxxxxxxxxxxxM@WWWW@@@@MMWWMMxxMW@@@@WWW@MxnnnnxxxxxMi'    'i'     '.''"
	@echo "''''''''..       ,n*nnnzzz#zz#######zznzxnxMWWWWWMxxxxxxxMM@WWWW@@W@WMMxxMW@@WWWWWWWWWWxxnnnnxxxM,              '.''"
	@echo "''''''''.'      ,ziznnxxxnnzz#z#zzznnxWxMWWWWWW@@@@@WMMMMWW@WWWW@@WW@WWW@@@@WWWWWWWWW@MxxnnnnxxM;               ..''"
	@echo "''''''''.'     '##znxnxxxxxxnnnnnnnxxM@WWWWWWWW@@WWW@@@@@@@WWWWW@WWMWW@@WW@@WWWWWWW@WMxxxxnnnnM;                ..''"
	@echo "''''''''.'         ',*nMMxxxxxxxxxxxxMMWWW@@@WW@@WWWWWWWWW@WWWW@@WMMMMWWWW@WWWWWWWWMMxxxxxnznz.                ...''"
	@echo "''''''''..             ,xMxxxxxxnnxMnnnnxWWWMMMW@WMMMMMWWW@@@@@#@WMxxxMMWW@@Mn##MMMMMxxxxxn#:                 '..'''"
	@echo "''''''''..              ,Mxxxnzznni'     '.;+nWW@WMMMMMMWWWMMMW@@WMxxxMMMn:.    ;WWWWMn#i,           '.'    '...''''"
	@echo "''''''''...              ;nxxz#i.             .+@WMxxxMMWWWMMMWMxW@MxxMMM.       '..'               ',.........'''''"
	@echo "'''''''''..'                                   :@WMxxxMMMWWWMM@@xznWWMMWi                          '.........'''''''"
	@echo "''''''''''...'                                 :@WMxxxxMMM,.'.WW@MzzW@@n                          ...'''''''''''''''"
	@echo "'''''''''''.......''                           ,@WMxxxxMMx   :@WW@@xnM@,                        '...''''''''''''''''"
	@echo "'''''''''''''......,'                          ,@WMxxxMMMn   #@WMxnMWW#                       '....'''''''''''''''''"
	@echo "''''''''''''''''''...'              '....      .@WMxxxMMW#   nxxnnMW@W.      ''           ''.....'''''''''''''''''''"
	@echo "''''''''''''''''''''...'         '......,'     '@@@WWWW@@*   +@@@WWW@*       ,,.''''''.........'''''''''''''''''''''"
	@echo "'''''''''''''''''''''................''..'     'WxnznnMMW;   .WWMMWWM'      '..............'''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''...........''''''.'     'W@WxnnxM@,    *@WMMW:       ...'''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''.'     'MW@@WW@@@'     #@W@+       ...''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''..      MxnxW@WWM       *Mz'      '..'''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''..      x@MMM@##n                 ..''''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''..      nMxnznxM+                '..''''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''..      zMMMMMW@;               '..'''''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''..      *@@WWW@M'               ..''''''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''..       inWWni'               ...''''''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''..'                   '      '...'''''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''''..                  ',..'.....'''''''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''''..'                 .........''''''''''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''''..                ...'''''''''''''''''''''''''''''''''''''''''''''''''''''"
	@echo "''''''''''''''''''''''''''''''''''''''''''...'            '...''''''''''''''''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''''''....'        '....'''''''''''''''''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''''''''.....'''......'''''''''''''''''''''''''''''''''''''''''''''''''''''''''"
	@echo "'''''''''''''''''''''''''''''''''''''''''''''''..........'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"

.PHONY :	all clean fclean re
# aoc
adventofcode challenge


## vimrc settings

```
colorscheme default
set tabstop=4
set softtabstop=0 noexpandtab
set shiftwidth=4
set number

:map <F2> :! make -j12<CR>
:map <F5> :w <CR>:! cd build; make -j4; ./test -s -r compact -d yes; ./app < ../test.txt; cd ..<CR>
:map <F6> :w <CR>:! cd build; make -j4; ./test --durations yes; cd ..<CR>
:map <F7> :w <CR>:! cd build; make -j4; ./app < ../test.txt; cd ..<CR>
```


## Graphical interface

## Graphs

2021 day2, a submarine that floats throu the ocean.

- [ ] Graph xy for position

## .gitconfig

[alias]
	l = log --pretty='%Cblue%aN%C(auto)%d %Creset%s' --graph --date=relative --date-order -20
	ll = log --pretty='%C(yellow)%h %C(cyan)%cd %Cblue%aN%C(auto)%d %Creset%s' --graph --date=relative --date-order -20
	lll = log --pretty='%C(yellow)%h %C(cyan)%cd %Cblue%aN%C(auto)%d %Creset%s' --graph --date-order
	s = status
	b = branch

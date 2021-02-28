" ========================= Vundle [Start] =========================
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" Plugins
Plugin 'L9'
Plugin 'altercation/vim-colors-solarized'
Plugin 'fugitive.vim'
Plugin 'airblade/vim-gitgutter'
Plugin 'Valloric/YouCompleteMe'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
Plugin 'majutsushi/tagbar'
Plugin 'elzr/vim-json'
Plugin 'https://github.com/ap/vim-css-color.git'
Plugin 'nvie/vim-flake8'
Plugin 'Vimjas/vim-python-pep8-indent'
Plugin 'suan/vim-instant-markdown', {'rtp': 'after'}

Plugin 'LucHermitte/lh-vim-lib'
Plugin 'LucHermitte/local_vimrc'
Plugin 'chrisbra/csv.vim'

call vundle#end()            " required
filetype plugin indent on    " required
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" vim +PluginInstall +qall
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
" ========================= Vundle [End] =========================

" Tab & Backspace configuration
set ts=4 sw=4 sts=4
autocmd FileType java setl ts=4 sw=4 sts=4 et
autocmd FileType python setl ts=4 sw=4 sts=4 textwidth=79 fileformat=unix smarttab et
set backspace=indent,eol,start
set smartindent
set cindent


" Color theme
syntax on
set background=dark
colorscheme solarized
hi Normal ctermbg=none

filetype plugin indent on

" misc
set number
set fileformat=unix 
set lazyredraw
set nobackup  
set noswapfile  
set nowb

" For regular expressions turn magic on
set magic

" Ignore compiled files
set wildignore=*.o,*~,*.pyc
set wildignore+=*/.git/*,*/.hg/*,*/.svn/*,*/.DS_Store

" set Tag
set tags=./tags;/,./TAGS;/
let Tlist_Auto_Open = 0

" Autoload CSCOPE database
function! LoadCscope()
	let db = findfile("cscope.out", ".;")
	if (!empty(db))
		let path = strpart(db, 0, match(db, "/cscope.out$"))
		set nocscopeverbose " suppress 'duplicate connection' error
		exe "cs add " . db . " " . path
		set cscopeverbose
	endif
endfunction
call LoadCscope()

" YCM settings - auto complete
"let g:ycm_min_num_of_chars_for_completion = 4
let g:ycm_autoclose_preview_window_after_completion = 1
let g:ycm_collect_identifiers_from_tags_files = 0
let g:ycm_complete_in_comments         = 1 " Completion in comments
let g:ycm_complete_in_strings          = 1 " Completion in string
let g:ycm_key_list_select_completion   = ['<C-n>', '<Down>']
let g:ycm_key_list_previous_completion = ['<C-p>', '<Up>']

" YCM settings - PYTHON
let g:ycm_python_binary_path = '/usr/bin/python3'

" YCM settings - misc
let g:ycm_confirm_extra_conf = 0
let g:ycm_show_diagnostics_ui = 1
let g:ycm_server_use_vim_stdout = 1
let g:ycm_server_log_level = 'debug'

" airline settings
set laststatus=2
let g:airline_powerline_fonts = 1
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#fnamemod = ':t'
let g:airline_theme='simple'







" Jerry original


" An example for a vimrc file.
"
" Maintainer:	Bram Moolenaar <Bram@vim.org>
" Last change:	2002 Sep 19
"
" To use it, copy it to
"     for Unix and OS/2:  ~/.vimrc
"	      for Amiga:  s:.vimrc
"  for MS-DOS and Win32:  $VIM\_vimrc
"	    for OpenVMS:  sys$login:.vimrc

" When started as "evim", evim.vim will already have done these settings.
if v:progname =~? "evim"
  finish
endif

" Use Vim settings, rather then Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
"set nocompatible

" allow backspacing over everything in insert mode
set ignorecase
set wrap!

"if has("vms")
"  set nobackup		" do not keep a backup file, use versions instead
"else
"  set backup		" keep a backup file
"endif
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set showcmd		" display incomplete commands
set incsearch		" do incremental searching

" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
map Q gq

" This is an alternative that also works in block mode, but the deleted
" text is lost and it only works for putting the current register.
"vnoremap p "_dp

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  "syntax on
  set hlsearch
endif

runtime ftplugin/man.vim

nnoremap <silent> <F3> :TagbarToggle<CR>
"map <F4> :tabnew<CR>

"map <F5> :tabp<CR>
"map <F6> :tabn<CR>
"map <F7> <ESC>:gr -r '\<<C-R><C-W>\>' *<CR>
"map <F8> <ESC>:gr '\<<C-R><C-W>\>' `find ./ -name "*.c"`<CR>

map <F5> <ESC>:gr '\<<C-R><C-W>\>' `find ./ -name "*.[ch]"`<CR>
map <F6> :cc<CR>
map <F7> :cp<CR>
map <F8> :cn<CR>

nmap <C-[>s :cs find s <C-R>=expand("<cword>")<CR><CR>   "키워드 검색
nmap <C-[>g :cs find g <C-R>=expand("<cword>")<CR><CR>   "선언 부분
nmap <C-[>c :cs find c <C-R>=expand("<cword>")<CR><CR>   "호출하는 부분
nmap <C-[>t :cs find t <C-R>=expand("<cword>")<CR><CR>   "문자열 검색
nmap <C-[>e :cs find e <C-R>=expand("<cword>")<CR><CR>   "확장 정규식 사용하여 검색
nmap <C-[>f :cs find f <C-R>=expand("<cfile>")<CR><CR>   "파일 검색색
nmap <C-[>i :cs find i <C-R>=expand("<cfile>")<CR><CR>   "include하는 부분
nmap <C-[>d :cs find d <C-R>=expand("<cword>")<CR><CR>   "호출하는 함수목록

set fileencodings=utf-8,euc-kr

set cinoptions=:0

" cscope setting
set csprg=/usr/bin/cscope
set csto=0
set cst

highlight ColorColumn ctermbg=blue
set colorcolumn=80

/*   HANGULCMT   */
/**------------------------------------------------------------------------

한글 주석 만들기 - 쁘렉키!! 쀍

만든이 : 단국대학교 MAZE 10기 전유훈

_2007/6/20_

edit : Hertz9th leejaeseong...

-------------------------------------------------------------------------*/
macro hangulcmt()
{
	sCmt = ask("주석 입력해 보더라고~ ( for _varhae_ )");
	sCmt = cat("//" sCmt);

	hWnd = GetCurrentWnd()
	inFirst = GetWndSelLnFirst(hWnd)
	hBuf = GetCurrentBuf()
	sCurrent = GetBufLine(hBuf, inFirst)
	
	DelBufLine(hBuf, inFirst);  
	InsBufLine(hBuf, inFirst, "@sCurrent@ @sCmt@");	
}


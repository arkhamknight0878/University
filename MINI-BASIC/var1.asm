
include\masm32\include\masm32rt.inc
;include\masm32\include\msvcrt.inc
;include\masm32\lib\msvcrt.lib

.386

    .data?

          hout  dd  ?
          x1  dd  ?
          buf  db  10 (?)
          ns  dd  ?
          x2  dd  ?

    .data
          x0      dd   13
          a       dd   5
          handle  dd   0

    .code
    start:
     
      call main
      exit

    main proc
      invoke   GetStdHandle,  STD_INPUT_HANDLE
      mov handle, eax

      print "vvod chisla",13,10
      invoke ReadConsole,handle,offset buf,size buf, offset ns, NULL
      invoke atol, offset buf
      mov  x2,eax
      mov  eax, a
      add  eax, x0
      add  eax, x2
      mov  x1,  eax
      print "OK",13,10
      invoke   GetStdHandle,  STD_OUTPUT_HANDLE
      mov hout,eax 
      invoke WriteConsole,hout,str$(x1),size x1,offset ns,NULL;
      ret
    main endp 
 end start





























include \masm32\include\masm32rt.inc

.386

.data?
x8 dd ?
x13 dd ?
x15 dd ?
x17 dd ?
x19 dd ?
x43 dd ?
x45 dd ?
x69 dd ?
x71 dd ?
x97 dd ?
x123 dd ?
x700	dd	?
x701	dd	?
x702	dd	?
x703	dd	?

.data
x0 dd 1
x287 dd 14
x288 dd 7
x289 dd 0
x290 dd 1
x291 dd 4
x292 dd 2
x293 dd 3
x294 dd 0
x295 dd 0
x296 dd 0
x297 dd 0
x298 dd 0
x299 dd 0
x300 dd 0
x301 dd 0
x302 dd 0
x303 dd 0
x304 dd 0
x305 dd 0
x306 dd 0

.code
start:
label_10:
mov eax, x287
mov x13, eax
label_20:
mov eax, x288
mov x15, eax
label_40:
mov eax, x13
mov x19, eax
label_50:
call label_1000
label_60:
je label_220
jl label_220
jg label_220
jle label_220
jge label_220
jne label_220
label_80:
mov eax, x15
mov x19, eax
label_90:
call label_1000
label_100:
je label_220
jl label_220
jg label_220
jle label_220
jge label_220
jne label_220
label_120:
mov eax, x289
mov x43, eax
label_140:
mov eax, x13
mov x19, eax
label_150:
call label_2000
label_160:
mov eax, x17
mov x43, eax
label_180:
mov eax, x15
mov x19, eax
label_190:
call label_2000
label_200:
mov eax, x17
add eax, x69
mov x294, eax
mov eax, x294
mov x43, eax
label_210:
jmp label_180
label_220:
mov eax, 0
sub eax, x290
mov x295, eax
mov eax, x295
mov x43, eax
label_230:
jmp label_5000
label_1000:
je label_1080
jl label_1080
jg label_1080
jle label_1080
jge label_1080
jne label_1080
label_1010:
jl label_1060
jg label_1060
jle label_1060
jge label_1060
jne label_1060
label_1020:
mov eax, x19
mov x45, eax
label_1030:
mov eax, x71
cdq
idiv x292
mov x296, eax
mov eax, x296
mov x71, eax
label_1040:
mov eax, x97
imul x292
mov x297, eax
mov eax, x297
mov x71, eax
label_1050:
mov eax, x71
sub eax, x97
mov x298, eax
mov eax, x298
mov x97, eax
label_1060:
je label_1160
jl label_1160
jg label_1160
jle label_1160
jge label_1160
jne label_1160
label_1070:
mov eax, x293
mov x8, eax
mov eax, x19
mov x700 , eax
mov eax, x292
mov x701 , eax
label_256:
mov eax, x8
cmp eax, x700
jg label_257
label_1080:
mov eax, x19
mov x45, eax
label_1090:
mov eax, x71
cdq
idiv x8
mov x299, eax
mov eax, x299
mov x71, eax
label_1100:
mov eax, x97
imul x8
mov x300, eax
mov eax, x300
mov x71, eax
label_1110:
mov eax, x71
sub eax, x97
mov x301, eax
mov eax, x301
mov x97, eax
label_1120:
je label_1160
jl label_1160
jg label_1160
jle label_1160
jge label_1160
jne label_1160
label_1130:
mov eax, x8
add eax, x701
mov x8, eax
jmp label_256
label_257:
label_1140:
mov eax, x290
mov x17, eax
label_1150:
jmp label_1170
label_1160:
mov eax, x289
mov x17, eax
label_1170:
ret
label_2000:
mov eax, x289
mov x17, eax
label_2010:
mov eax, x19
mov x8, eax
mov eax, x289
mov x702 , eax
mov eax, x290
mov x703 , eax
label_258:
mov eax, x8
cmp eax, x702
jg label_259
label_2020:
mov eax, x8
mov x45, eax
label_2030:
mov eax, x71
cdq
idiv x293
mov x302, eax
mov eax, x302
mov x71, eax
label_2040:
mov eax, x97
imul x293
mov x303, eax
mov eax, x303
mov x71, eax
label_2050:
mov eax, x71
sub eax, x97
mov x304, eax
mov eax, x304
mov x97, eax
label_2060:
je label_2100
jl label_2100
jg label_2100
jle label_2100
jge label_2100
jne label_2100
label_2070:
mov eax, x8
cdq
idiv x293
mov x305, eax
mov eax, x305
mov x8, eax
label_2080:
mov eax, x8
add eax, x703
mov x8, eax
jmp label_258
label_259:
label_2090:
ret
label_2100:
mov eax, x290
add eax, x17
mov x306, eax
mov eax, x306
mov x17, eax
label_2110:
jmp label_2070
label_5000:
print str$(x17),10,13
end start
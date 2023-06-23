[ORG  0x7c00]

[SECTION .text]
[BITS 16]
global _start
_start:
    ; 设置屏幕模式为文本模式，清除屏幕
    mov ax, 3
    int 0x10
    ; 清空寄存器
    mov     ax, 0
    mov     ss, ax
    mov     ds, ax
    mov     es, ax
    mov     fs, ax
    mov     gs, ax
    mov     si, ax
    ; 传参数
    mov     si, msg
    call    print

    jmp     $

; 如何调用
; mov     si, msg   ; 1 传入字符串
; call    print     ; 2 调用
print:
    mov ah, 0x0e
    mov bh, 0
    mov bl, 0x01
.loop:
    mov al, [si]
    cmp al, 0
    jz .done
    int 0x10

    inc si
    jmp .loop
.done:
    ret

msg:
    db "hello, world", 10, 13, 0

; 将 512 内存除了代码以及最后的2位(55aa) 填充0
times 512 -2 - ($ - $$) db 0 ;重复  512(内存大小) - 2（末尾的55aa）- ($ - $$)(当前位置 - 段开始位置) db(声明字节) 0
db 0x55, 0xaa
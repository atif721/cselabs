.model small
.stack 100h
.data

a db 'Enter the number: $'
b db 13, 10, 'Result is: $'

.code

main proc

    mov ax, @data
    mov ds, ax

    mov ah,9
    lea dx,a
    int 21h

    mov ah,1
    int 21h
    mov bl, al
    
    mov ah,9
    lea dx,b
    int 21h

    ;Compare input
    cmp bl,'1'
    je odd      ; JE = Jump if equal
    cmp bl,'3'
    je odd
    cmp bl,'2'
    je even
    cmp bl,'4'
    je even

    jmp exit    ;if not 1,2,3,4

odd:
    mov dl,'o'
    jmp display

even:
    mov dl,'e'
    jmp display

display:
    mov ah,2
    int 21h

exit:
    mov ah,4ch
    int 21h
main endp
end main
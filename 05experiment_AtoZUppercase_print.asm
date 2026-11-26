.model small
.stack 100h
.code    

main proc
    mov ah, 1
    int 21h

    cmp al, 'A'
    jb exit
    ; If AL < 'A', exit.

    cmp al, 'Z'
    ja exit
    ; If AL > 'Z', exit.
    
    mov bl, al
                             
    mov ah,2           
    mov dl,13
    int 21h
    mov dl,10
    int 21h 
                  
    mov dl, bl
    int 21h

exit:
    mov ah, 4ch
    int 21h

main endp
end main
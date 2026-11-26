.model small
.stack 100h
.code

main proc
    mov cx,80
    mov ah,2
    mov dl, '*'
    
    loop2:
    int 21h
    loop loop2:
    
    exit:
    mov ah,4ch
    int 21h   
    main endp
end main

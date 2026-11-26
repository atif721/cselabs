.model small
.stack 100h

.data 
a db '* * * * *', 13, 10, '$'

.code

main proc
    mov ax,@data
    mov ds,ax
    
    mov cx,5
    
    mov ah,9
    lea dx,a
    
    loop2:
    int 21h  
    loop loop2:
    
    exit:
    mov ah,4ch
    int 21h   
    main endp
end main
                    
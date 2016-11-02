global loader						; entry symbol for ELF

MAGIC_NUMBER	  equ 0x1BADB002			; define magic number constant
FLAGS		  equ 0x0				; multiboot flags
CHECKSUM	  equ -MAGIC_NUMBER			; calculate checksum
							; (magic number + checksum + flags should equal zero)
KERNEL_STACK_SIZE equ 4096				; size of stack in bytes (64 * 64)

section .bss
align 4							; align at 4 bytes
kernel_stack:						; label points to beginning of memory 
	resb KERNEL_STACK_SIZE				; reserve stack for the kernel
	
section .text:						; start of text (code) section
align 4							; code must be 4 byte aligned
	dd MAGIC_NUMBER					; write magic number to machine code,
	dd FLAGS					; the flags, 
	dd CHECKSUM					; and the checksum

loader:							; loader label (defined as entry point in linker script)
	mov eax, 0xCAFEBABE				; place number 0xCAFEBABE in register eax
	mov esp, kernel_stack + KERNEL_STACK_SIZE	; point esp to start of stack (end of memory area)
	mov word [0x000B8000], 0x4128			; write ascii 'A' to top left of screen
	mov word ebx, [0x000b8000]			; copy value there to register

.loop:
	jmp .loop					;loop forever


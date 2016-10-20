global loader				; entry symbol for ELF

MAGIC_NUMBER	equ 0x1BADB002		; define magic number constant
FLAGS		equ 0x0			; multiboot flags
CHECKSUM	equ -MAGIC_NUMBER	; calculate checksum
					; (magic number + checksum + flags should equal zero)

section .text:				; start of text (code) section
align 4					; code must be 4 byte aligned
	dd MAGIC_NUMBER			; write magic number to machine code,
	dd FLAGS			; the flags, 
	dd CHECKSUM			; and the checksum

loader:					; loader label (defined as entry point in linker script)
	mov eax, 0xCAFEBABE		; place number 0xCAFEBABE in register eax
.loop:
	jmp .loop			;loop forever


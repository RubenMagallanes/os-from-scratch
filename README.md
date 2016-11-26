# os-from-scratch
writing a basic operating system pretty much from scratch. instructions taken from littleosbook


current stage: Pretty Colors 

  OS sets up a stack so C code can be called. 
  A main function is called, then the OS loops indefinitely. 
  The main function 'kmain' currently prints a green 'A' character in each corner of
  the screen, then exits. 
  
  The following commands are run from the makefile when "$ make run" is executed. 
  
  compile loader.s into 32 bit ELF with: $ nasm -f elf32 loader.s

  link executable with: $ ld -T link.ld -melf_i386 loader.o -o kernel.elf
  
  build ISO : 
   $ genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -A os \
      -input-charset utf8 -quiet -boot-info-table -o os.iso iso

  use command "$ bochs -qf bochsrc.txt" to boot OS.
  
  useful bochs commands: 
    
    s [number] step $number of cpu cycles through execution.
    
    c continue execution
    r print registers and contents
    x dump memory - use "x /[n]hx 0x000B8000" to view 'n' framebuffer characters, /nbx to seperate by bytes, and /nbt to view in binary

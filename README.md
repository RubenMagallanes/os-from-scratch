# os-from-scratch
writing a basic operating system pretty much from scratch. instructions taken from littleosbook


current stage: hello cafebabe. 
  OS loads 0xCAFEBABE into the EAX register, then loops infinitely.
  
  compile loader.s into 32 bit ELF with : 
    "$ nasm -f elf32 loader.s"
  link executable with : 
    "$ ld -T link.ld -melf_i386 loader.o -o kernel.elf"
  build ISO : 
    genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -A os \
      -input-charset utf8 -quiet -boot-info-table -o os.iso iso
  use command "$ bochs -qf bochsrc.txt" to boot OS.
  bochs commands: 
    s [number] step $number of cpu cycles through execution.
    c continue execution
    r print registers and contents


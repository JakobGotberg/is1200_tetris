  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.global time2string
.global delay


.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
  .data


  .text
main:

hexasc:
  andi $a0, $a0, 0xf  #bitmask 
  addi $v0, $a0, 0x30 #add 30 to get the ascii char
  jr $ra
  nop
    
 delay:
  PUSH $ra
  PUSH $s0
  PUSH $s1
  move  $t0, $0
  addi  $t0, $t0, 1   # $t0 = 1, needed in loop2
 # srl $a0, $a0, 3   # make $a0 smaller, useful since the constant can't go below 0.
loop1:  ble   $a0, $0, done   # if $a0 = 0, outer loop is done
  nop 
  addi  $a0, $a0, -1    #ms--
  move  $s0, $0     #int i = 0
loop2:  slti  $s1, $s0, 4711  #constant changes depending on computers mood
  addi  $s0, $s0, 1   # i++   
  beq $s1, $t0, loop2   # if i < constant, stay in forloop
  nop
  beq   $s1, $0, loop1
  nop
done: 
  POP $s1
  POP $s0
  POP $ra
  jr  $ra
  nop
  
 time2string:
  PUSH $s0
  PUSH $s1
  
  move  $s0, $a0
  move  $s1, $a1  
  PUSH $ra   
 
  srl   $a0, $s1, 12  #first diget
  jal   hexasc
  nop
  sb  $v0, 0($s0)
  
  
  srl $a0, $a1, 8 #secound diget
  jal hexasc
  nop
  sb  $v0, 1($s0)
    
  move  $t3, $0
  li  $t3, 0x3a # ':'
  sb  $t3, 2($s0)
  
  srl   $a0, $a1, 4 #third diget
  jal hexasc
  nop
  sb  $v0, 3($s0) 
  
  move  $a0, $a1  #last diget
  jal hexasc
  nop
  sb  $v0, 4($s0)
  
  li  $v0, 0x00 #\0
  sb  $v0, 5($s0)
  
  POP $ra
  POP $s1
  POP $s0
  jr  $ra
  nop
 
  
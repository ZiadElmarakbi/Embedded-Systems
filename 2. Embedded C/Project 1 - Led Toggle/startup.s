
.section .vectors

/* SRAM 0x20000000 */
.word 0x20001000
.word _reset
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler


.section .text
_reset:
bl main
b . // branch back to main
.thumb_func

vector_handler:
b _reset

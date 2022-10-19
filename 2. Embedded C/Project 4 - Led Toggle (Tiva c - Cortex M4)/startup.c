
// Eng. Ziad Mohamed Elbendary _ 


#include <Typedefs.h> // AUTOSAR defined typedef convention.  
// #define start_sp 0x20001000

// Prototypes 
extern int main(void); 
void reset_handler(void);

// Aliased Function (Unifiable Function)
void default_handler (){

	reset_handler();
}

/* weak attribute makes the prototypted function modifiable in any other file so that we can overwrite it 
   if needed. Such functions can only be called and not redefined. If weak attribute wasn't declared and we 
   tried to modify or redefine the function in any other file, an error will appear stating that we are redefining 
   the function again.

    Alasing will group all the selected functions to a single unity function, it will allow X number of functions 
    to have the same address as the unified function.Thus saving memory space. If we take any of the functions that 
    has weak and alias attributes and tried to modify it in another file, the alias will break and such a function 
    will have a unique address on its own. 
*/

void NMI_handler(void) __attribute__((weak, alias ("default_handler")));;
void H_fault_handler(void)__attribute__((weak, alias ("default_handler")));;
void NM_fault_handler(void)__attribute__((weak, alias ("default_handler")));;
void Bus_fault(void)__attribute__((weak, alias ("default_handler")));;
void Usage_fault_handler(void)__attribute__((weak, alias ("default_handler")));;


/*Reserving 1024bytes located @ /bss Mem. Section through uninitialized array
	of 256 integer elements (256*4 = 1024bytes) */

static unsigned int stack_top[256]; /* Using a global static type will make the 
													 stack_top visibility and scope within this 
													 file only so it's unmodifiable in any other 
													 file */ 

// uint32 vectors[]__attribute__((section(".vectors"))) = {

// 						(uint32) (stack_top + sizeof(stack_top)), 
// 						(uint32) &reset_handler, 
// 						(uint32) &NMI_handler,
// 						(uint32) &NM_fault_handler,
// 						(uint32) &H_fault_handler,
// 						(uint32) &Bus_fault,
// 						(uint32) &Usage_fault_handler
// 	};

/* Second Way: (Array of pointers, pointing to a function which takes 
	anything and return void) */

 void  (* arr_p_func[])()__attribute__((section(".vectors"))) = {

 	  (void (*)()) (&stack_top[0] + sizeof(stack_top)),
 					   &reset_handler, 
						&NMI_handler,
						&NM_fault_handler,
						&H_fault_handler,
						&Bus_fault,
						&Usage_fault_handler
	};


extern uint32  _E_Text_ ;
extern uint32 	_S_data_ ;
extern uint32	_E_data_ ;
extern uint32	_S_bss_ ;
extern uint32	_E_bss_ ;

// Send byte by byte from ROM to RAM for .data section

void reset_handler(void){

uint32 Data_Size = (uint8*)&_E_data_ - (uint8*)&_S_data_;
uint8* P_dest = (uint8*)&_S_data_;
uint8* P_src = (uint8*)&_E_Text_;
uint32 i; 

for(i = 0; i < Data_Size; i++){

*((uint8*)P_dest++) = *((uint8*)P_src++);

} 

// Initialize the .bss section with zeros

// uint32 bss_size = (uint8*)&_E_bss_ - (uint8*) &_S_bss_;
// P_dest = (uint8*)&_S_bss_;

// for(i = 0; i<bss_size; i++){

// 	*((uint8*)P_dest++) = (uint8)0;

// }

// Goto Main 

	main();
}





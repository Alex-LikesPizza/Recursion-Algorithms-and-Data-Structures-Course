#include <iostream>
#include <windows.h>

int main() {
    // Define the "Hello, World!" string in the data section
    const char hello[] = "Hello, World!\n";

    asm(
        // Inline assembly for Windows API
        "mov rax, QWORD PTR fs:0x30\n\t"  // Get the PEB address
        "mov rax, QWORD PTR [rax + 0x60]\n\t"  // Get the ProcessParameters address
        "mov rax, QWORD PTR [rax + 0x70]\n\t"  // Get the CommandLine address
        "mov rdx, rax\n\t"  // Save the CommandLine address in rdx

        // Inline assembly for WriteFile
        "mov r9, rdx\n\t"  // Set the CommandLine address as the buffer
        "mov r8d, 13\n\t"  // Set the buffer size (length of "Hello, World!\n")
        "lea rdx, [rip + hello]\n\t"  // Load the address of the "Hello, World!\n" string
        "mov rcx, 1\n\t"  // Set the file handle (stdout)
        "mov eax, 0x54\n\t"  // Set the system call number for WriteFile
        "syscall"
    );

    return 0;
}
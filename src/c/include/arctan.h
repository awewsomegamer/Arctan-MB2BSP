/**
 * @file arctan.h
 *
 * @author awewsomegamer <awewsomegamer@gmail.com>
 *
 * @LICENSE
 * Arctan-MB2BSP - Multiboot2 Bootstrapper for Arctan Kernel
 * Copyright (C) 2023-2024 awewsomegamer
 *
 * This file is part of Arctan-MB2BSP
 *
 * Arctan is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @DESCRIPTION
 * Arctan header file.
*/
#ifndef ARC_ARCTAN_H
#define ARC_ARCTAN_H

#include <stdint.h>

#define ARC_HHDM_VADDR _boot_meta.hhdm_vaddr
#define ARC_PHYS_TO_HHDM(physical) ((uintptr_t)(physical) + (uintptr_t)ARC_HHDM_VADDR)
#define ARC_TO_HHDM_PHYS(hhdm) ((uintptr_t)(hhdm) - (uintptr_t)ARC_HHDM_VADDR)

#define ARC_BOOTPROC_ARCTAN 1
#define ARC_BOOTPROC_MB2    2
#define ARC_BOOTPROC_LBP    3

struct ARC_KernMeta {

}__attribute__((packed));

struct ARC_MMap {
	int type;
	uint64_t base;
	uint64_t len;
}__attribute__((packed));

struct ARC_BootMeta {
	/// The boot protocol used.
	int boot_proc;
	/// Pointer to the physical address of the bootloader information.
	uint64_t boot_info;
	/// Physical pointer to the state of the bootstrapper's PMM (of type struct ARC_FreelsitMeta).
	uint64_t pmm_state;
	/// The highest physical address.
	uint64_t highest_address;
	/// Pointer to the base of the kernel module.
	uint64_t kernel_elf;
	/// Pointer to the base of the initramfs module.
	uint64_t initramfs;
	/// The size of the initramfs module.
	uint32_t initramfs_size;
	/// State of the last kernel.
	uint64_t state;
	/// Beginning of the HHDM (vaddr).
	uint64_t hhdm_vaddr;
	/// Arctan specific memory map (paddr).
	uint64_t arc_mmap;
	/// Length of arc_mmap.
	int arc_mmap_len;
	/// RSDP address.
	uint64_t rsdp;
}__attribute__((packed));

#endif

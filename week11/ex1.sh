#!/bin/bash

# run as root

dd if=/dev/zero of=lofs.img count=50 bs=1MiB

losetup -fP lofs.img
mkfs.ext4 lofs.img

mkdir -p lofsdisk
mount -o loop lofs.img lofsdisk

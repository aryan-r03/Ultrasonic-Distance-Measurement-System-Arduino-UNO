import serial
import pygame
import subprocess
import time

# ================= SERIAL CONFIG =================
PORT = "/dev/ttyUSB0"   # macOS (often): /dev/tty.usbserial-XXXX
BAUD = 9600

ser = serial.Serial(PORT, BAUD, timeout=1)
time.sleep(2)

# ================= GUI CONFIG =================
pygame.init()
WIDTH, HEIGHT = 600, 300
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Object Distance Monitor")

font_big = pygame.font.SysFont("Arial", 48, bold=True)
font_small = pygame.font.SysFont("Arial", 22)

BLACK = (15, 15, 15)
GREEN = (0, 255, 140)
YELLOW = (255, 200, 0)
RED = (255, 80, 80)

clock = pygame.time.Clock()

display_distance = "--"


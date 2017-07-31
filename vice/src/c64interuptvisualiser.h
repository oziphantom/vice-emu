/*
* c64interuptvisualiser.h - Lets you see when IRQs and NMI happen
*
* Written by
*  Daniel Hotop <oziphantom@hotmail.com>
*
* This file is part of VICE, the Versatile Commodore Emulator.
* See README for copyright notice.
*
*  This program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software
*  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
*  02111-1307  USA.
*
*/

#ifndef VICE_C64_INTERUPT_VISUALISER
#define VICE_C64_INTERUPT_VISUALISER

enum eIRQVisualMode {
    irq_vis_mode_none = -1,
    irq_vis_mode_IRQ = 0,
    irq_vis_mode_NMI = 1
};

extern void irq_visualiser_push_IRQ(void);
extern void irq_visualiser_push_NMI(void);
extern void irq_visualiser_pull(void);
extern enum eIRQVisualMode irq_visualiser_get_current_state(void);
extern void irq_visualiser_enable(void);
extern void irq_viusaliser_disable(void);
extern void irq_visualiser_reset(void);
extern int irq_visualiser_is_enabled(void);
#endif //VICE_C64_INTERUPT_VISUALISER
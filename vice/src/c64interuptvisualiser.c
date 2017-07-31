 
#include "c64interuptvisualiser.h"
#include "log.h"

#define irqVis_max_stack 16

static enum eIRQVisualMode g_stack[irqVis_max_stack];
static int g_current_index = 0;
static int g_enable = 0;

static char* tabString[irqVis_max_stack] =
{
    "",
    "\t",
    "\t\t",
    "\t\t\t",
    "\t\t\t\t",
    "\t\t\t\t\t",
    "\t\t\t\t\t\t",
    "\t\t\t\t\t\t\t",
    "\t\t\t\t\t\t\t\t",
    "\t\t\t\t\t\t\t\t\t",
    "\t\t\t\t\t\t\t\t\t",
    "\t\t\t\t\t\t\t\t\t",
    "\t\t\t\t\t\t\t\t\t",
    "\t\t\t\t\t\t\t\t\t",
    "\t\t\t\t\t\t\t\t\t",
    "\t\t\t\t\t\t\t\t\t"
};

void irq_visualiser_push_IRQ(void)
{
    if (g_enable)
    {
        if (g_current_index < irqVis_max_stack - 1)
        {
            g_current_index++;
            g_stack[g_current_index] = irq_vis_mode_IRQ;
            //log_message(LOG_ERR, "IRQ:%spush", tabString[g_current_index]);
        }
    }
}

void irq_visualiser_push_NMI(void)
{
    if (g_enable)
    {
        if (g_current_index < irqVis_max_stack - 1)
        {
            g_current_index++;
            g_stack[g_current_index] = irq_vis_mode_NMI;
            //log_message(LOG_ERR, "NMI:%spush", tabString[g_current_index]);
        }
    }
}

void irq_visualiser_pull(void)
{
    if (g_current_index)
    {
        //if (g_stack[g_current_index] == irq_vis_mode_IRQ) { log_message(LOG_ERR, "IRQ:%sPull", tabString[g_current_index]); }
        //else if (g_stack[g_current_index] == irq_vis_mode_NMI) { log_message(LOG_ERR, "NMI:%sPull", tabString[g_current_index]); }
        g_current_index--;
    }
}

enum eIRQVisualMode irq_visualiser_get_current_state(void)
{
    return g_stack[g_current_index];
}

void irq_visualiser_enable(void)
{
    g_enable = 1; 
}

void irq_viusaliser_disable(void)
{
    g_enable = 0;
}

void irq_visualiser_reset(void)
{
    g_current_index = 0;
    g_stack[0] = irq_vis_mode_none;        
}

int irq_visualiser_is_enabled(void)
{
    return g_enable;
}
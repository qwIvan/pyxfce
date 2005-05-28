/* Generated by GOB (v2.0.9)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>
#ifndef __XFCE_MCS_MANAGER_H__
#define __XFCE_MCS_MANAGER_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



#include <gtk/gtk.h>
#include <libxfce4mcs/mcs-manager.h>
#include "xfce-mcs-channel.h"


/*
 * Type checking and casting macros
 */
#define XFCE_TYPE_MCS_MANAGER	(xfce_mcs_manager_get_type())
#define XFCE_MCS_MANAGER(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mcs_manager_get_type(), XfceMcsManager)
#define XFCE_MCS_MANAGER_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mcs_manager_get_type(), XfceMcsManager const)
#define XFCE_MCS_MANAGER_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), xfce_mcs_manager_get_type(), XfceMcsManagerClass)
#define XFCE_IS_MCS_MANAGER(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), xfce_mcs_manager_get_type ())

#define XFCE_MCS_MANAGER_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), xfce_mcs_manager_get_type(), XfceMcsManagerClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_XFCE_MCS_MANAGER__
#define __TYPEDEF_XFCE_MCS_MANAGER__
typedef struct _XfceMcsManager XfceMcsManager;
#endif
struct _XfceMcsManager {
	GObject __parent__;
	/*< private >*/
	McsManager * low; /* protected */
	GHashTable * channels; /* protected */
	GHashTable * channels_r; /* protected */
};

/*
 * Class definition
 */
typedef struct _XfceMcsManagerClass XfceMcsManagerClass;
struct _XfceMcsManagerClass {
	GObjectClass __parent__;
};


/*
 * Public methods
 */
GType	xfce_mcs_manager_get_type	(void);
XfceMcsManager * 	xfce_mcs_manager_new	(McsManager * manager);
void 	xfce_mcs_manager_register_channel	(XfceMcsManager * self,
					XfceMcsChannel * channel);
void 	xfce_mcs_manager_unregister_channel	(XfceMcsManager * self,
					XfceMcsChannel * channel);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

/* Generated by GOB (v2.0.9) on Sat May 28 15:05:35 2005
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 9

#define selfp (self->_priv)

#include "xfce-mcs-client.h"

#include "xfce-mcs-client-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 1 "xfce-mcs-client.gob"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#include <gdk/gdkx.h>

static void
weak_notify_cb(gpointer data, GObject *where_the_object_was)
{
	xfce_mcs_client_vanish_object (XFCE_MCS_CLIENT (data), where_the_object_was);
}

static void
notify_cb(const gchar *name, const gchar *channel_name,
  McsAction action, McsSetting * setting, void *cb_data)
{
	g_warning ("NOTIFY");
	xfce_mcs_client_setting_changed (XFCE_MCS_CLIENT (cb_data), name, channel_name, action, setting);
}

static GdkFilterReturn
client_event_filter (GdkXEvent * xevent, GdkEvent * event, gpointer data)
{
	XfceMcsClient	*c;
	McsClient	*m;
	
	c = (XfceMcsClient *)data;
	m = c->low;
	if (!m)
		return GDK_FILTER_REMOVE;
	
	if (mcs_client_process_event ((McsClient*) m, (XEvent *) xevent))
		return GDK_FILTER_REMOVE;
	else
		return GDK_FILTER_CONTINUE;
}

static void
watch_cb(Window window, gboolean is_start, long mask, void *data)
{
	GdkWindow *gdkwin;

	gdkwin = gdk_window_lookup (window);
        
	if (is_start)
		gdk_window_add_filter (gdkwin, client_event_filter, data);
	else
		gdk_window_remove_filter (gdkwin, client_event_filter, data);
}

static gboolean
my_ascii_strcasecmp(gconstpointer a, gconstpointer b)
{
	return g_ascii_strcasecmp ((gchar const *)a, (gchar const *)b) == 0;
}


#line 89 "xfce-mcs-client.c"

#line 62 "xfce-mcs-client.gob"

#include <gtk/gtk.h>
#include <libxfce4mcs/mcs-client.h>
#include "xfce-mcs-channel.h"

#line 97 "xfce-mcs-client.c"
/* self casting macros */
#define SELF(x) XFCE_MCS_CLIENT(x)
#define SELF_CONST(x) XFCE_MCS_CLIENT_CONST(x)
#define IS_SELF(x) XFCE_IS_MCS_CLIENT(x)
#define TYPE_SELF XFCE_TYPE_MCS_CLIENT
#define SELF_CLASS(x) XFCE_MCS_CLIENT_CLASS(x)

#define SELF_GET_CLASS(x) XFCE_MCS_CLIENT_GET_CLASS(x)

/* self typedefs */
typedef XfceMcsClient Self;
typedef XfceMcsClientClass SelfClass;

/* here are local prototypes */
static void ___object_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
static void ___object_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);
static void xfce_mcs_client_class_init (XfceMcsClientClass * c) G_GNUC_UNUSED;
static void ___real_xfce_mcs_client_manager_reconnect (XfceMcsClient * self);
static void xfce_mcs_client_init (XfceMcsClient * self) G_GNUC_UNUSED;

/*
 * Signal connection wrapper macro shortcuts
 */
#define self_connect__manager_reconnect(object,func,data)	xfce_mcs_client_connect__manager_reconnect((object),(func),(data))
#define self_connect_after__manager_reconnect(object,func,data)	xfce_mcs_client_connect_after__manager_reconnect((object),(func),(data))
#define self_connect_data__manager_reconnect(object,func,data,destroy_data,flags)	xfce_mcs_client_connect_data__manager_reconnect((object),(func),(data),(destroy_data),(flags))

enum {
	MANAGER_RECONNECT_SIGNAL,
	LAST_SIGNAL
};

enum {
	PROP_0,
	PROP_SCREEN
};

static guint object_signals[LAST_SIGNAL] = {0};

/* pointer to the class of our parent */
static GObjectClass *parent_class = NULL;

/* Short form macros */
#define self_get_screen xfce_mcs_client_get_screen
#define self_set_screen xfce_mcs_client_set_screen
#define self_manager_reconnect xfce_mcs_client_manager_reconnect
#define self_new xfce_mcs_client_new
#define self_vanish_object xfce_mcs_client_vanish_object
#define self_delete_channel xfce_mcs_client_delete_channel
#define self_add_channel xfce_mcs_client_add_channel
#define self_setting_changed xfce_mcs_client_setting_changed
#define self_get_setting xfce_mcs_client_get_setting
#define self_check_manager xfce_mcs_client_check_manager
#define self_show_dialog xfce_mcs_client_show_dialog
GType
xfce_mcs_client_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (XfceMcsClientClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) xfce_mcs_client_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (XfceMcsClient),
			0 /* n_preallocs */,
			(GInstanceInitFunc) xfce_mcs_client_init,
			NULL
		};

		type = g_type_register_static (G_TYPE_OBJECT, "XfceMcsClient", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((XfceMcsClient *)g_object_new(xfce_mcs_client_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static XfceMcsClient * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static XfceMcsClient *
GET_NEW_VARG (const char *first, ...)
{
	XfceMcsClient *ret;
	va_list ap;
	va_start (ap, first);
	ret = (XfceMcsClient *)g_object_new_valist (xfce_mcs_client_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::finalize"
	XfceMcsClient *self  G_GNUC_UNUSED = XFCE_MCS_CLIENT (obj_self);
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#define low (self->low)
#define VAR low
	{
#line 70 "xfce-mcs-client.gob"
	
			mcs_client_destroy (VAR);
			VAR = NULL;
		}
#line 210 "xfce-mcs-client.c"
	memset(&low, 0, sizeof(low));
#undef VAR
#undef low
#define channels (self->channels)
#define VAR channels
	{
#line 76 "xfce-mcs-client.gob"
	
			g_hash_table_destroy (VAR);
		}
#line 221 "xfce-mcs-client.c"
	memset(&channels, 0, sizeof(channels));
#undef VAR
#undef channels
#define channels_r (self->channels_r)
#define VAR channels_r
	{
#line 81 "xfce-mcs-client.gob"
	
			g_hash_table_destroy (VAR);
		}
#line 232 "xfce-mcs-client.c"
	memset(&channels_r, 0, sizeof(channels_r));
#undef VAR
#undef channels_r
#define screen (self->screen)
#define VAR screen
	{
#line 86 "xfce-mcs-client.gob"
	
			if (VAR)
				g_object_unref ((GdkScreen *)VAR);
			VAR = NULL;
		}
#line 245 "xfce-mcs-client.c"
	memset(&screen, 0, sizeof(screen));
#undef VAR
#undef screen
}
#undef __GOB_FUNCTION__

static void 
xfce_mcs_client_class_init (XfceMcsClientClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::class_init"
	GObjectClass *g_object_class G_GNUC_UNUSED = (GObjectClass*) c;

	parent_class = g_type_class_ref (G_TYPE_OBJECT);

	object_signals[MANAGER_RECONNECT_SIGNAL] =
		g_signal_new ("manager_reconnect",
			G_TYPE_FROM_CLASS (g_object_class),
			(GSignalFlags)(G_SIGNAL_RUN_FIRST | G_SIGNAL_ACTION),
			G_STRUCT_OFFSET (XfceMcsClientClass, manager_reconnect),
			NULL, NULL,
			g_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE, 0);

#line 124 "xfce-mcs-client.gob"
	c->manager_reconnect = ___real_xfce_mcs_client_manager_reconnect;
#line 271 "xfce-mcs-client.c"
	g_object_class->finalize = ___finalize;
	g_object_class->get_property = ___object_get_property;
	g_object_class->set_property = ___object_set_property;
    {
	GParamSpec   *param_spec;

	param_spec = g_param_spec_object
		("screen" /* name */,
		 "the screen to use" /* nick */,
		 "The GdkScreen to use for the settings" /* blurb */,
		 GDK_TYPE_SCREEN /* object_type */,
		 (GParamFlags)(G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (g_object_class,
		PROP_SCREEN,
		param_spec);
    }
}
#undef __GOB_FUNCTION__
#line 148 "xfce-mcs-client.gob"
static void 
xfce_mcs_client_init (XfceMcsClient * self G_GNUC_UNUSED)
#line 293 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::init"
#line 62 "xfce-mcs-client.gob"
	self->low = NULL;
#line 298 "xfce-mcs-client.c"
#line 81 "xfce-mcs-client.gob"
	self->screen = NULL;
#line 301 "xfce-mcs-client.c"
 {
#line 149 "xfce-mcs-client.gob"

		self->channels = g_hash_table_new_full (g_str_hash, my_ascii_strcasecmp,
			g_free, NULL);

		self->channels_r = g_hash_table_new (g_direct_hash, g_direct_equal);
		
		g_object_set ((GObject *)self, "screen", gdk_screen_get_default (), NULL);
	
#line 312 "xfce-mcs-client.c"
 }
}
#undef __GOB_FUNCTION__

static void
___object_set_property (GObject *object,
	guint property_id,
	const GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::set_property"
{
	XfceMcsClient *self G_GNUC_UNUSED;

	self = XFCE_MCS_CLIENT (object);

	switch (property_id) {
	case PROP_SCREEN:
		{
#line 97 "xfce-mcs-client.gob"

			Display*	dpy;
			GdkScreen*	screen;
			screen = g_value_get_object (VAL);
			if (self->screen) {
				g_object_unref (G_OBJECT (self->screen));
				self->screen = NULL;
			}

			if (screen)
				self->screen = (GdkScreen *) g_object_ref (screen);
	
			if (self->low) {
				mcs_client_destroy (self->low);
				self->low = NULL;
			}
	
			dpy = GDK_DISPLAY_XDISPLAY (gdk_screen_get_display (screen));
			self->low = mcs_client_new (dpy, gdk_screen_get_number (screen), notify_cb, watch_cb, self);
	
			/* g_signal_emit_by_name (self, "manager-reconnect", NULL); */
			self_manager_reconnect (self); /* suffices */
		
#line 355 "xfce-mcs-client.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
#undef __GOB_FUNCTION__

static void
___object_get_property (GObject *object,
	guint property_id,
	GValue *VAL G_GNUC_UNUSED,
	GParamSpec *pspec G_GNUC_UNUSED)
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::get_property"
{
	XfceMcsClient *self G_GNUC_UNUSED;

	self = XFCE_MCS_CLIENT (object);

	switch (property_id) {
	case PROP_SCREEN:
		{
#line 120 "xfce-mcs-client.gob"

			g_value_set_object (VAL, self->screen);
		
#line 388 "xfce-mcs-client.c"
		}
		break;
	default:
/* Apparently in g++ this is needed, glib is b0rk */
#ifndef __PRETTY_FUNCTION__
#  undef G_STRLOC
#  define G_STRLOC	__FILE__ ":" G_STRINGIFY (__LINE__)
#endif
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}
#undef __GOB_FUNCTION__


#line 120 "xfce-mcs-client.gob"
GObject * 
xfce_mcs_client_get_screen (XfceMcsClient * self)
#line 407 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::get_screen"
{
#line 92 "xfce-mcs-client.gob"
		GObject* val; g_object_get (G_OBJECT (self), "screen", &val, NULL); return val;
}}
#line 414 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

#line 97 "xfce-mcs-client.gob"
void 
xfce_mcs_client_set_screen (XfceMcsClient * self, GObject * val)
#line 420 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::set_screen"
{
#line 92 "xfce-mcs-client.gob"
		g_object_set (G_OBJECT (self), "screen", val, NULL);
}}
#line 427 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

#line 124 "xfce-mcs-client.gob"
void 
xfce_mcs_client_manager_reconnect (XfceMcsClient * self)
#line 433 "xfce-mcs-client.c"
{
	GValue ___param_values[1];
	GValue ___return_val;

memset (&___return_val, 0, sizeof (___return_val));
memset (&___param_values, 0, sizeof (___param_values));

#line 124 "xfce-mcs-client.gob"
	g_return_if_fail (self != NULL);
#line 124 "xfce-mcs-client.gob"
	g_return_if_fail (XFCE_IS_MCS_CLIENT (self));
#line 445 "xfce-mcs-client.c"

	___param_values[0].g_type = 0;
	g_value_init (&___param_values[0], G_TYPE_FROM_INSTANCE (self));
	g_value_set_instance (&___param_values[0], (gpointer) self);

	g_signal_emitv (___param_values,
		object_signals[MANAGER_RECONNECT_SIGNAL],
		0 /* detail */,
		&___return_val);

	g_value_unset (&___param_values[0]);
}
#line 124 "xfce-mcs-client.gob"
static void 
___real_xfce_mcs_client_manager_reconnect (XfceMcsClient * self G_GNUC_UNUSED)
#line 461 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::manager_reconnect"
{
#line 126 "xfce-mcs-client.gob"
	
		self_check_manager (self);
	}}
#line 469 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

#line 130 "xfce-mcs-client.gob"
XfceMcsClient * 
xfce_mcs_client_new (void)
#line 475 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::new"
{
#line 131 "xfce-mcs-client.gob"
	
		XfceMcsClient *obj;
		obj = (XfceMcsClient *)GET_NEW;
		return obj;
	}}
#line 485 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

#line 137 "xfce-mcs-client.gob"
void 
xfce_mcs_client_vanish_object (XfceMcsClient * self, GObject * obj)
#line 491 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::vanish_object"
#line 137 "xfce-mcs-client.gob"
	g_return_if_fail (self != NULL);
#line 137 "xfce-mcs-client.gob"
	g_return_if_fail (XFCE_IS_MCS_CLIENT (self));
#line 498 "xfce-mcs-client.c"
{
#line 138 "xfce-mcs-client.gob"
	
		gchar*	channel_name;
		channel_name = g_hash_table_lookup (self->channels_r, obj);
		g_hash_table_remove (self->channels_r, obj);
		if (channel_name) {
			g_hash_table_remove (self->channels, channel_name);
			/* remove also frees channel_name */
		}
	}}
#line 510 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__


#line 159 "xfce-mcs-client.gob"
void 
xfce_mcs_client_delete_channel (XfceMcsClient * self, gchar const * name)
#line 517 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::delete_channel"
#line 159 "xfce-mcs-client.gob"
	g_return_if_fail (self != NULL);
#line 159 "xfce-mcs-client.gob"
	g_return_if_fail (XFCE_IS_MCS_CLIENT (self));
#line 524 "xfce-mcs-client.c"
{
#line 160 "xfce-mcs-client.gob"
	
		if (!self->low) {
			g_warning ("XfceMcsClient: delete_channel: property screen not set.");
			return;
		}
		mcs_client_delete_channel (self->low, name);
	}}
#line 534 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

#line 168 "xfce-mcs-client.gob"
XfceMcsChannel * 
xfce_mcs_client_add_channel (XfceMcsClient * self, gchar const * name)
#line 540 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::add_channel"
#line 168 "xfce-mcs-client.gob"
	g_return_val_if_fail (self != NULL, (XfceMcsChannel * )0);
#line 168 "xfce-mcs-client.gob"
	g_return_val_if_fail (XFCE_IS_MCS_CLIENT (self), (XfceMcsChannel * )0);
#line 547 "xfce-mcs-client.c"
{
#line 169 "xfce-mcs-client.gob"
	
		gpointer	obj;
		gchar*		xname;
		obj = g_hash_table_lookup (self->channels, name);

		if (obj)
			return XFCE_MCS_CHANNEL (obj);

		obj = xfce_mcs_channel_new (self, XFCE_MCS_CHANNEL_SIDE_CLIENT, name);
		g_object_weak_ref ((GObject *)obj, weak_notify_cb, self);
		xname = g_strdup (name);
		g_hash_table_insert (self->channels, xname, obj);
		g_hash_table_insert (self->channels_r, obj, xname);
		return obj;
	}}
#line 565 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

#line 186 "xfce-mcs-client.gob"
void 
xfce_mcs_client_setting_changed (XfceMcsClient * self, gchar const * name, gchar const * channel_name, McsAction action, McsSetting * setting)
#line 571 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::setting_changed"
#line 186 "xfce-mcs-client.gob"
	g_return_if_fail (self != NULL);
#line 186 "xfce-mcs-client.gob"
	g_return_if_fail (XFCE_IS_MCS_CLIENT (self));
#line 578 "xfce-mcs-client.c"
{
#line 187 "xfce-mcs-client.gob"
	
		gpointer	obj;
		obj = g_hash_table_lookup (self->channels, channel_name);
		if (obj) {
			switch (action) {
			case MCS_ACTION_NEW:
				xfce_mcs_channel_setting_added (XFCE_MCS_CHANNEL (obj), name);
				xfce_mcs_channel_setting_changed (XFCE_MCS_CHANNEL (obj), name); /* just in case the client monitors just one */
				break;
		
			case MCS_ACTION_CHANGED:
				xfce_mcs_channel_setting_changed (XFCE_MCS_CHANNEL (obj), name);
				break;
				
			case MCS_ACTION_DELETED:
				xfce_mcs_channel_setting_deleted (XFCE_MCS_CHANNEL (obj), name);
				break;
			}
		}
	}}
#line 601 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

#line 208 "xfce-mcs-client.gob"
McsSetting * 
xfce_mcs_client_get_setting (XfceMcsClient * self, gchar const * channel_name, gchar const * name)
#line 607 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::get_setting"
#line 208 "xfce-mcs-client.gob"
	g_return_val_if_fail (self != NULL, (McsSetting * )0);
#line 208 "xfce-mcs-client.gob"
	g_return_val_if_fail (XFCE_IS_MCS_CLIENT (self), (McsSetting * )0);
#line 614 "xfce-mcs-client.c"
{
#line 209 "xfce-mcs-client.gob"
	
		McsSetting*	setting;
		setting = NULL;
		if (mcs_client_get_setting (self->low, name, channel_name, &setting) == MCS_SUCCESS) {
		} else
			setting = NULL;

		return setting;
	}}
#line 626 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

#line 219 "xfce-mcs-client.gob"
gboolean 
xfce_mcs_client_check_manager (XfceMcsClient * self)
#line 632 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::check_manager"
#line 219 "xfce-mcs-client.gob"
	g_return_val_if_fail (self != NULL, (gboolean )0);
#line 219 "xfce-mcs-client.gob"
	g_return_val_if_fail (XFCE_IS_MCS_CLIENT (self), (gboolean )0);
#line 639 "xfce-mcs-client.c"
{
#line 220 "xfce-mcs-client.gob"
	
		Display*	dpy;
		
		if (self->screen == NULL)
			return FALSE;
		
		dpy = GDK_DISPLAY_XDISPLAY (gdk_screen_get_display (self->screen));
		return mcs_client_check_manager (dpy, gdk_screen_get_number (self->screen), "xfce-mcs-manager");
	}}
#line 651 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

#line 230 "xfce-mcs-client.gob"
void 
xfce_mcs_client_show_dialog (XfceMcsClient * self, gchar const * message)
#line 657 "xfce-mcs-client.c"
{
#define __GOB_FUNCTION__ "Xfce:Mcs:Client::show_dialog"
#line 230 "xfce-mcs-client.gob"
	g_return_if_fail (self != NULL);
#line 230 "xfce-mcs-client.gob"
	g_return_if_fail (XFCE_IS_MCS_CLIENT (self));
#line 664 "xfce-mcs-client.c"
{
#line 231 "xfce-mcs-client.gob"
	
		Display*	dpy;
		if (!self->screen) {
			g_warning ("XfceMcsClient: show_dialog: screen property is NULL, not showing dialog.");
			return;
		}
			
		dpy = GDK_DISPLAY_XDISPLAY (gdk_screen_get_display (self->screen));
		mcs_client_show (dpy, gdk_screen_get_number (self->screen), message);
	}}
#line 677 "xfce-mcs-client.c"
#undef __GOB_FUNCTION__

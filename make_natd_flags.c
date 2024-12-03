#include <stdio.h>

#define laliari "10.0.0.1"
#define laura "10.0.0.13"
#define israel "10.0.0.4"
#define elliana "10.0.0.12"
#define teracluster "10.0.0.6"
#define videohead "10.0.0.13"
#define slab "10.0.0.8"
#define voicebox "10.0.0.27"
#define jdg_w541_w10 "10.0.0.15"
#define jdg_w541_w10_vm "10.0.0.23"
#define alternator "10.0.0.23"

#define winnspare "10.0.0.10"

#define tcp "tcp"
#define udp "udp"

#define ftp "21"
#define http "80"
#define auth "113"
#define https "443"
#define rdp "3389"
#define alt_rdp "4389"
#define vncrev "5500"
#define irc "6660-6670"
#define torrent "6881"
#define alt_irc "7000"
#define alt_http "8080"
#define sing "5000"
#define webcam_proxy "8887"
#define webcam "8888"
#define webcam_tls "443" /* for Let's Encrypt */
#define dynmap_http "8123"
#define emule_tcp "4662"
#define emule_udp "4672"
#define vuze_tcp "22421"
#define vuze_tcp_2 "15486"
#define skype_tcp "36673"
#define minecraft_tcp "25565"
#define dogland_outside_tcp "25566"
#define dogland_inside_tcp "25565"
#define vuze_tcp_3 "35716"

struct redirection
{
  const char *inside_ip;
  const char *protocol;
  const char *inside_port_range;
  const char *outside_port_range;
};

struct redirection redirections[] =
  {
//    { israel,		tcp, auth,	auth		},
    { laura,		tcp, alt_http,	alt_http	},
    { laura,		tcp, torrent,	torrent		},
    { laura,            udp, torrent,   torrent         },
    { laura,            tcp, skype_tcp, skype_tcp       },
    { teracluster,	tcp, http,	"10240"		},
    { teracluster,	tcp, ftp,	"10181"		},
    { elliana,		tcp, http,	http		},
    { elliana,          tcp, https,     https           },
    { elliana,          tcp, https,     "444" },
    { elliana,		tcp, irc,	irc		},
    { elliana,		tcp, alt_irc,	alt_irc		},

    { laura,		tcp, emule_tcp,	emule_tcp	},
    { laura,		udp, emule_udp,	emule_udp	},
    { laura,            tcp, dogland_inside_tcp, dogland_outside_tcp },
    { laura,            tcp, webcam_proxy, webcam       },
    /*{ laura,            tcp, webcam_tls, webcam_tls     },*/

    { jdg_w541_w10,     tcp, sing, sing                 },
    { jdg_w541_w10_vm,  tcp, rdp, alt_rdp               },

    { videohead,        tcp, vuze_tcp,  vuze_tcp        },

    { slab,             tcp, minecraft_tcp, minecraft_tcp },
    { slab,             tcp, dynmap_http, dynmap_http   },

    { winnspare,        tcp, vncrev,    vncrev          },

    { voicebox,         tcp, vuze_tcp_2, vuze_tcp_2     },
    { voicebox,         udp, vuze_tcp_2, vuze_tcp_2     },

    { alternator,       tcp, vuze_tcp_3, vuze_tcp_3     },
    { alternator,       udp, vuze_tcp_3, vuze_tcp_3     },

    { NULL, NULL, NULL, NULL }
  };

int main()
{
  // -redirect_port tcp insideip:insideport outsideport
  int i;

  for (i=0; redirections[i].inside_ip != NULL; i++)
    printf("-redirect_port %s %s:%s %s ",
      redirections[i].protocol,
      redirections[i].inside_ip,
      redirections[i].inside_port_range,
      redirections[i].outside_port_range);

  return 0;
}


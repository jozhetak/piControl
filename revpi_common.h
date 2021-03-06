#include <linux/sched.h>

enum revpi_power_led_mode {
	REVPI_POWER_LED_OFF = 0,
	REVPI_POWER_LED_ON = 1,
	REVPI_POWER_LED_FLICKR = 2,
	REVPI_POWER_LED_ON_500MS = 3,
	REVPI_POWER_LED_ON_1000MS = 4,
};

void revpi_led_trigger_event(uint8_t *led_prev, uint8_t led);
void revpi_power_led_red_set(enum revpi_power_led_mode mode);
void revpi_power_led_red_run(void);

void revpi_check_timeout(void);

int bcm2835_cpufreq_clock_property(u32 tag, u32 id, u32 * val);
uint32_t bcm2835_cpufreq_get_clock(void);
extern char *lock_file;
extern int lock_line;

#if 0
//#define my_rt_mutex_lock(P)	if (rt_mutex_is_locked(P)) pr_err("mutex already locked: " __FILE__ " %d %d", __LINE__, (P)->owner->pid);

#define my_rt_mutex_lock(P)	if (rt_mutex_is_locked(P)) pr_err("mutex already locked by %d %s\nnow: %d " __FILE__ "\n", lock_line, lock_file, __LINE__); \
				lock_file = __FILE__; lock_line = __LINE__; \
				rt_mutex_lock(P);
#else
#define my_rt_mutex_lock(P)	rt_mutex_lock(P)
#endif

struct kthread_prio {
	const char comm[TASK_COMM_LEN];
	int prio;
};

int set_kthread_prios(const struct kthread_prio *ktprios);

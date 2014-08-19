// MESSAGE VICON_6Q PACKING

#define MAVLINK_MSG_ID_VICON_6Q 226

typedef struct __mavlink_vicon_6q_t
{
 int16_t t_1; ///< thrust cmd
 int16_t r_1; ///< roll cmd
 int16_t p_1; ///< pitch cmd
 int16_t y_1; ///< yaw cmd
 int16_t pwm_1; ///< pwm cmd
 int16_t t_2; ///< thrust cmd
 int16_t r_2; ///< roll cmd
 int16_t p_2; ///< pitch cmd
 int16_t y_2; ///< yaw cmd
 int16_t pwm_2; ///< pwm cmd
 int16_t t_3; ///< thrust cmd
 int16_t r_3; ///< roll cmd
 int16_t p_3; ///< pitch cmd
 int16_t y_3; ///< yaw cmd
 int16_t pwm_3; ///< pwm cmd
 int16_t t_4; ///< thrust cmd
 int16_t r_4; ///< roll cmd
 int16_t p_4; ///< pitch cmd
 int16_t y_4; ///< yaw cmd
 int16_t pwm_4; ///< pwm cmd
 int16_t t_5; ///< thrust cmd
 int16_t r_5; ///< roll cmd
 int16_t p_5; ///< pitch cmd
 int16_t y_5; ///< yaw cmd
 int16_t pwm_5; ///< pwm cmd
 int16_t t_6; ///< thrust cmd
 int16_t r_6; ///< roll cmd
 int16_t p_6; ///< pitch cmd
 int16_t y_6; ///< yaw cmd
 int16_t pwm_6; ///< pwm cmd
 uint8_t mode_1; ///< Quad ID
 uint8_t mode_2; ///< Quad ID
 uint8_t mode_3; ///< Quad ID
 uint8_t mode_4; ///< Quad ID
 uint8_t mode_5; ///< Quad ID
 uint8_t mode_6; ///< Quad ID
} mavlink_vicon_6q_t;

#define MAVLINK_MSG_ID_VICON_6Q_LEN 66
#define MAVLINK_MSG_ID_226_LEN 66



#define MAVLINK_MESSAGE_INFO_VICON_6Q { \
	"VICON_6Q", \
	36, \
	{  { "t_1", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_vicon_6q_t, t_1) }, \
         { "r_1", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_vicon_6q_t, r_1) }, \
         { "p_1", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_vicon_6q_t, p_1) }, \
         { "y_1", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_vicon_6q_t, y_1) }, \
         { "pwm_1", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_vicon_6q_t, pwm_1) }, \
         { "t_2", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_vicon_6q_t, t_2) }, \
         { "r_2", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_vicon_6q_t, r_2) }, \
         { "p_2", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_vicon_6q_t, p_2) }, \
         { "y_2", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_vicon_6q_t, y_2) }, \
         { "pwm_2", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_vicon_6q_t, pwm_2) }, \
         { "t_3", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_vicon_6q_t, t_3) }, \
         { "r_3", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_vicon_6q_t, r_3) }, \
         { "p_3", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_vicon_6q_t, p_3) }, \
         { "y_3", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_vicon_6q_t, y_3) }, \
         { "pwm_3", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_vicon_6q_t, pwm_3) }, \
         { "t_4", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_vicon_6q_t, t_4) }, \
         { "r_4", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_vicon_6q_t, r_4) }, \
         { "p_4", NULL, MAVLINK_TYPE_INT16_T, 0, 34, offsetof(mavlink_vicon_6q_t, p_4) }, \
         { "y_4", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_vicon_6q_t, y_4) }, \
         { "pwm_4", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_vicon_6q_t, pwm_4) }, \
         { "t_5", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_vicon_6q_t, t_5) }, \
         { "r_5", NULL, MAVLINK_TYPE_INT16_T, 0, 42, offsetof(mavlink_vicon_6q_t, r_5) }, \
         { "p_5", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_vicon_6q_t, p_5) }, \
         { "y_5", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_vicon_6q_t, y_5) }, \
         { "pwm_5", NULL, MAVLINK_TYPE_INT16_T, 0, 48, offsetof(mavlink_vicon_6q_t, pwm_5) }, \
         { "t_6", NULL, MAVLINK_TYPE_INT16_T, 0, 50, offsetof(mavlink_vicon_6q_t, t_6) }, \
         { "r_6", NULL, MAVLINK_TYPE_INT16_T, 0, 52, offsetof(mavlink_vicon_6q_t, r_6) }, \
         { "p_6", NULL, MAVLINK_TYPE_INT16_T, 0, 54, offsetof(mavlink_vicon_6q_t, p_6) }, \
         { "y_6", NULL, MAVLINK_TYPE_INT16_T, 0, 56, offsetof(mavlink_vicon_6q_t, y_6) }, \
         { "pwm_6", NULL, MAVLINK_TYPE_INT16_T, 0, 58, offsetof(mavlink_vicon_6q_t, pwm_6) }, \
         { "mode_1", NULL, MAVLINK_TYPE_UINT8_T, 0, 60, offsetof(mavlink_vicon_6q_t, mode_1) }, \
         { "mode_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 61, offsetof(mavlink_vicon_6q_t, mode_2) }, \
         { "mode_3", NULL, MAVLINK_TYPE_UINT8_T, 0, 62, offsetof(mavlink_vicon_6q_t, mode_3) }, \
         { "mode_4", NULL, MAVLINK_TYPE_UINT8_T, 0, 63, offsetof(mavlink_vicon_6q_t, mode_4) }, \
         { "mode_5", NULL, MAVLINK_TYPE_UINT8_T, 0, 64, offsetof(mavlink_vicon_6q_t, mode_5) }, \
         { "mode_6", NULL, MAVLINK_TYPE_UINT8_T, 0, 65, offsetof(mavlink_vicon_6q_t, mode_6) }, \
         } \
}


/**
 * @brief Pack a vicon_6q message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode_1 Quad ID
 * @param t_1 thrust cmd
 * @param r_1 roll cmd
 * @param p_1 pitch cmd
 * @param y_1 yaw cmd
 * @param pwm_1 pwm cmd
 * @param mode_2 Quad ID
 * @param t_2 thrust cmd
 * @param r_2 roll cmd
 * @param p_2 pitch cmd
 * @param y_2 yaw cmd
 * @param pwm_2 pwm cmd
 * @param mode_3 Quad ID
 * @param t_3 thrust cmd
 * @param r_3 roll cmd
 * @param p_3 pitch cmd
 * @param y_3 yaw cmd
 * @param pwm_3 pwm cmd
 * @param mode_4 Quad ID
 * @param t_4 thrust cmd
 * @param r_4 roll cmd
 * @param p_4 pitch cmd
 * @param y_4 yaw cmd
 * @param pwm_4 pwm cmd
 * @param mode_5 Quad ID
 * @param t_5 thrust cmd
 * @param r_5 roll cmd
 * @param p_5 pitch cmd
 * @param y_5 yaw cmd
 * @param pwm_5 pwm cmd
 * @param mode_6 Quad ID
 * @param t_6 thrust cmd
 * @param r_6 roll cmd
 * @param p_6 pitch cmd
 * @param y_6 yaw cmd
 * @param pwm_6 pwm cmd
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_6q_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t mode_1, int16_t t_1, int16_t r_1, int16_t p_1, int16_t y_1, int16_t pwm_1, uint8_t mode_2, int16_t t_2, int16_t r_2, int16_t p_2, int16_t y_2, int16_t pwm_2, uint8_t mode_3, int16_t t_3, int16_t r_3, int16_t p_3, int16_t y_3, int16_t pwm_3, uint8_t mode_4, int16_t t_4, int16_t r_4, int16_t p_4, int16_t y_4, int16_t pwm_4, uint8_t mode_5, int16_t t_5, int16_t r_5, int16_t p_5, int16_t y_5, int16_t pwm_5, uint8_t mode_6, int16_t t_6, int16_t r_6, int16_t p_6, int16_t y_6, int16_t pwm_6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[66];
	_mav_put_int16_t(buf, 0, t_1);
	_mav_put_int16_t(buf, 2, r_1);
	_mav_put_int16_t(buf, 4, p_1);
	_mav_put_int16_t(buf, 6, y_1);
	_mav_put_int16_t(buf, 8, pwm_1);
	_mav_put_int16_t(buf, 10, t_2);
	_mav_put_int16_t(buf, 12, r_2);
	_mav_put_int16_t(buf, 14, p_2);
	_mav_put_int16_t(buf, 16, y_2);
	_mav_put_int16_t(buf, 18, pwm_2);
	_mav_put_int16_t(buf, 20, t_3);
	_mav_put_int16_t(buf, 22, r_3);
	_mav_put_int16_t(buf, 24, p_3);
	_mav_put_int16_t(buf, 26, y_3);
	_mav_put_int16_t(buf, 28, pwm_3);
	_mav_put_int16_t(buf, 30, t_4);
	_mav_put_int16_t(buf, 32, r_4);
	_mav_put_int16_t(buf, 34, p_4);
	_mav_put_int16_t(buf, 36, y_4);
	_mav_put_int16_t(buf, 38, pwm_4);
	_mav_put_int16_t(buf, 40, t_5);
	_mav_put_int16_t(buf, 42, r_5);
	_mav_put_int16_t(buf, 44, p_5);
	_mav_put_int16_t(buf, 46, y_5);
	_mav_put_int16_t(buf, 48, pwm_5);
	_mav_put_int16_t(buf, 50, t_6);
	_mav_put_int16_t(buf, 52, r_6);
	_mav_put_int16_t(buf, 54, p_6);
	_mav_put_int16_t(buf, 56, y_6);
	_mav_put_int16_t(buf, 58, pwm_6);
	_mav_put_uint8_t(buf, 60, mode_1);
	_mav_put_uint8_t(buf, 61, mode_2);
	_mav_put_uint8_t(buf, 62, mode_3);
	_mav_put_uint8_t(buf, 63, mode_4);
	_mav_put_uint8_t(buf, 64, mode_5);
	_mav_put_uint8_t(buf, 65, mode_6);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 66);
#else
	mavlink_vicon_6q_t packet;
	packet.t_1 = t_1;
	packet.r_1 = r_1;
	packet.p_1 = p_1;
	packet.y_1 = y_1;
	packet.pwm_1 = pwm_1;
	packet.t_2 = t_2;
	packet.r_2 = r_2;
	packet.p_2 = p_2;
	packet.y_2 = y_2;
	packet.pwm_2 = pwm_2;
	packet.t_3 = t_3;
	packet.r_3 = r_3;
	packet.p_3 = p_3;
	packet.y_3 = y_3;
	packet.pwm_3 = pwm_3;
	packet.t_4 = t_4;
	packet.r_4 = r_4;
	packet.p_4 = p_4;
	packet.y_4 = y_4;
	packet.pwm_4 = pwm_4;
	packet.t_5 = t_5;
	packet.r_5 = r_5;
	packet.p_5 = p_5;
	packet.y_5 = y_5;
	packet.pwm_5 = pwm_5;
	packet.t_6 = t_6;
	packet.r_6 = r_6;
	packet.p_6 = p_6;
	packet.y_6 = y_6;
	packet.pwm_6 = pwm_6;
	packet.mode_1 = mode_1;
	packet.mode_2 = mode_2;
	packet.mode_3 = mode_3;
	packet.mode_4 = mode_4;
	packet.mode_5 = mode_5;
	packet.mode_6 = mode_6;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 66);
#endif

	msg->msgid = MAVLINK_MSG_ID_VICON_6Q;
	return mavlink_finalize_message(msg, system_id, component_id, 66, 74);
}

/**
 * @brief Pack a vicon_6q message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode_1 Quad ID
 * @param t_1 thrust cmd
 * @param r_1 roll cmd
 * @param p_1 pitch cmd
 * @param y_1 yaw cmd
 * @param pwm_1 pwm cmd
 * @param mode_2 Quad ID
 * @param t_2 thrust cmd
 * @param r_2 roll cmd
 * @param p_2 pitch cmd
 * @param y_2 yaw cmd
 * @param pwm_2 pwm cmd
 * @param mode_3 Quad ID
 * @param t_3 thrust cmd
 * @param r_3 roll cmd
 * @param p_3 pitch cmd
 * @param y_3 yaw cmd
 * @param pwm_3 pwm cmd
 * @param mode_4 Quad ID
 * @param t_4 thrust cmd
 * @param r_4 roll cmd
 * @param p_4 pitch cmd
 * @param y_4 yaw cmd
 * @param pwm_4 pwm cmd
 * @param mode_5 Quad ID
 * @param t_5 thrust cmd
 * @param r_5 roll cmd
 * @param p_5 pitch cmd
 * @param y_5 yaw cmd
 * @param pwm_5 pwm cmd
 * @param mode_6 Quad ID
 * @param t_6 thrust cmd
 * @param r_6 roll cmd
 * @param p_6 pitch cmd
 * @param y_6 yaw cmd
 * @param pwm_6 pwm cmd
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_6q_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode_1,int16_t t_1,int16_t r_1,int16_t p_1,int16_t y_1,int16_t pwm_1,uint8_t mode_2,int16_t t_2,int16_t r_2,int16_t p_2,int16_t y_2,int16_t pwm_2,uint8_t mode_3,int16_t t_3,int16_t r_3,int16_t p_3,int16_t y_3,int16_t pwm_3,uint8_t mode_4,int16_t t_4,int16_t r_4,int16_t p_4,int16_t y_4,int16_t pwm_4,uint8_t mode_5,int16_t t_5,int16_t r_5,int16_t p_5,int16_t y_5,int16_t pwm_5,uint8_t mode_6,int16_t t_6,int16_t r_6,int16_t p_6,int16_t y_6,int16_t pwm_6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[66];
	_mav_put_int16_t(buf, 0, t_1);
	_mav_put_int16_t(buf, 2, r_1);
	_mav_put_int16_t(buf, 4, p_1);
	_mav_put_int16_t(buf, 6, y_1);
	_mav_put_int16_t(buf, 8, pwm_1);
	_mav_put_int16_t(buf, 10, t_2);
	_mav_put_int16_t(buf, 12, r_2);
	_mav_put_int16_t(buf, 14, p_2);
	_mav_put_int16_t(buf, 16, y_2);
	_mav_put_int16_t(buf, 18, pwm_2);
	_mav_put_int16_t(buf, 20, t_3);
	_mav_put_int16_t(buf, 22, r_3);
	_mav_put_int16_t(buf, 24, p_3);
	_mav_put_int16_t(buf, 26, y_3);
	_mav_put_int16_t(buf, 28, pwm_3);
	_mav_put_int16_t(buf, 30, t_4);
	_mav_put_int16_t(buf, 32, r_4);
	_mav_put_int16_t(buf, 34, p_4);
	_mav_put_int16_t(buf, 36, y_4);
	_mav_put_int16_t(buf, 38, pwm_4);
	_mav_put_int16_t(buf, 40, t_5);
	_mav_put_int16_t(buf, 42, r_5);
	_mav_put_int16_t(buf, 44, p_5);
	_mav_put_int16_t(buf, 46, y_5);
	_mav_put_int16_t(buf, 48, pwm_5);
	_mav_put_int16_t(buf, 50, t_6);
	_mav_put_int16_t(buf, 52, r_6);
	_mav_put_int16_t(buf, 54, p_6);
	_mav_put_int16_t(buf, 56, y_6);
	_mav_put_int16_t(buf, 58, pwm_6);
	_mav_put_uint8_t(buf, 60, mode_1);
	_mav_put_uint8_t(buf, 61, mode_2);
	_mav_put_uint8_t(buf, 62, mode_3);
	_mav_put_uint8_t(buf, 63, mode_4);
	_mav_put_uint8_t(buf, 64, mode_5);
	_mav_put_uint8_t(buf, 65, mode_6);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 66);
#else
	mavlink_vicon_6q_t packet;
	packet.t_1 = t_1;
	packet.r_1 = r_1;
	packet.p_1 = p_1;
	packet.y_1 = y_1;
	packet.pwm_1 = pwm_1;
	packet.t_2 = t_2;
	packet.r_2 = r_2;
	packet.p_2 = p_2;
	packet.y_2 = y_2;
	packet.pwm_2 = pwm_2;
	packet.t_3 = t_3;
	packet.r_3 = r_3;
	packet.p_3 = p_3;
	packet.y_3 = y_3;
	packet.pwm_3 = pwm_3;
	packet.t_4 = t_4;
	packet.r_4 = r_4;
	packet.p_4 = p_4;
	packet.y_4 = y_4;
	packet.pwm_4 = pwm_4;
	packet.t_5 = t_5;
	packet.r_5 = r_5;
	packet.p_5 = p_5;
	packet.y_5 = y_5;
	packet.pwm_5 = pwm_5;
	packet.t_6 = t_6;
	packet.r_6 = r_6;
	packet.p_6 = p_6;
	packet.y_6 = y_6;
	packet.pwm_6 = pwm_6;
	packet.mode_1 = mode_1;
	packet.mode_2 = mode_2;
	packet.mode_3 = mode_3;
	packet.mode_4 = mode_4;
	packet.mode_5 = mode_5;
	packet.mode_6 = mode_6;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 66);
#endif

	msg->msgid = MAVLINK_MSG_ID_VICON_6Q;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 66, 74);
}

/**
 * @brief Encode a vicon_6q struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vicon_6q C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vicon_6q_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vicon_6q_t* vicon_6q)
{
	return mavlink_msg_vicon_6q_pack(system_id, component_id, msg, vicon_6q->mode_1, vicon_6q->t_1, vicon_6q->r_1, vicon_6q->p_1, vicon_6q->y_1, vicon_6q->pwm_1, vicon_6q->mode_2, vicon_6q->t_2, vicon_6q->r_2, vicon_6q->p_2, vicon_6q->y_2, vicon_6q->pwm_2, vicon_6q->mode_3, vicon_6q->t_3, vicon_6q->r_3, vicon_6q->p_3, vicon_6q->y_3, vicon_6q->pwm_3, vicon_6q->mode_4, vicon_6q->t_4, vicon_6q->r_4, vicon_6q->p_4, vicon_6q->y_4, vicon_6q->pwm_4, vicon_6q->mode_5, vicon_6q->t_5, vicon_6q->r_5, vicon_6q->p_5, vicon_6q->y_5, vicon_6q->pwm_5, vicon_6q->mode_6, vicon_6q->t_6, vicon_6q->r_6, vicon_6q->p_6, vicon_6q->y_6, vicon_6q->pwm_6);
}

/**
 * @brief Send a vicon_6q message
 * @param chan MAVLink channel to send the message
 *
 * @param mode_1 Quad ID
 * @param t_1 thrust cmd
 * @param r_1 roll cmd
 * @param p_1 pitch cmd
 * @param y_1 yaw cmd
 * @param pwm_1 pwm cmd
 * @param mode_2 Quad ID
 * @param t_2 thrust cmd
 * @param r_2 roll cmd
 * @param p_2 pitch cmd
 * @param y_2 yaw cmd
 * @param pwm_2 pwm cmd
 * @param mode_3 Quad ID
 * @param t_3 thrust cmd
 * @param r_3 roll cmd
 * @param p_3 pitch cmd
 * @param y_3 yaw cmd
 * @param pwm_3 pwm cmd
 * @param mode_4 Quad ID
 * @param t_4 thrust cmd
 * @param r_4 roll cmd
 * @param p_4 pitch cmd
 * @param y_4 yaw cmd
 * @param pwm_4 pwm cmd
 * @param mode_5 Quad ID
 * @param t_5 thrust cmd
 * @param r_5 roll cmd
 * @param p_5 pitch cmd
 * @param y_5 yaw cmd
 * @param pwm_5 pwm cmd
 * @param mode_6 Quad ID
 * @param t_6 thrust cmd
 * @param r_6 roll cmd
 * @param p_6 pitch cmd
 * @param y_6 yaw cmd
 * @param pwm_6 pwm cmd
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vicon_6q_send(mavlink_channel_t chan, uint8_t mode_1, int16_t t_1, int16_t r_1, int16_t p_1, int16_t y_1, int16_t pwm_1, uint8_t mode_2, int16_t t_2, int16_t r_2, int16_t p_2, int16_t y_2, int16_t pwm_2, uint8_t mode_3, int16_t t_3, int16_t r_3, int16_t p_3, int16_t y_3, int16_t pwm_3, uint8_t mode_4, int16_t t_4, int16_t r_4, int16_t p_4, int16_t y_4, int16_t pwm_4, uint8_t mode_5, int16_t t_5, int16_t r_5, int16_t p_5, int16_t y_5, int16_t pwm_5, uint8_t mode_6, int16_t t_6, int16_t r_6, int16_t p_6, int16_t y_6, int16_t pwm_6)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[66];
	_mav_put_int16_t(buf, 0, t_1);
	_mav_put_int16_t(buf, 2, r_1);
	_mav_put_int16_t(buf, 4, p_1);
	_mav_put_int16_t(buf, 6, y_1);
	_mav_put_int16_t(buf, 8, pwm_1);
	_mav_put_int16_t(buf, 10, t_2);
	_mav_put_int16_t(buf, 12, r_2);
	_mav_put_int16_t(buf, 14, p_2);
	_mav_put_int16_t(buf, 16, y_2);
	_mav_put_int16_t(buf, 18, pwm_2);
	_mav_put_int16_t(buf, 20, t_3);
	_mav_put_int16_t(buf, 22, r_3);
	_mav_put_int16_t(buf, 24, p_3);
	_mav_put_int16_t(buf, 26, y_3);
	_mav_put_int16_t(buf, 28, pwm_3);
	_mav_put_int16_t(buf, 30, t_4);
	_mav_put_int16_t(buf, 32, r_4);
	_mav_put_int16_t(buf, 34, p_4);
	_mav_put_int16_t(buf, 36, y_4);
	_mav_put_int16_t(buf, 38, pwm_4);
	_mav_put_int16_t(buf, 40, t_5);
	_mav_put_int16_t(buf, 42, r_5);
	_mav_put_int16_t(buf, 44, p_5);
	_mav_put_int16_t(buf, 46, y_5);
	_mav_put_int16_t(buf, 48, pwm_5);
	_mav_put_int16_t(buf, 50, t_6);
	_mav_put_int16_t(buf, 52, r_6);
	_mav_put_int16_t(buf, 54, p_6);
	_mav_put_int16_t(buf, 56, y_6);
	_mav_put_int16_t(buf, 58, pwm_6);
	_mav_put_uint8_t(buf, 60, mode_1);
	_mav_put_uint8_t(buf, 61, mode_2);
	_mav_put_uint8_t(buf, 62, mode_3);
	_mav_put_uint8_t(buf, 63, mode_4);
	_mav_put_uint8_t(buf, 64, mode_5);
	_mav_put_uint8_t(buf, 65, mode_6);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VICON_6Q, buf, 66, 74);
#else
	mavlink_vicon_6q_t packet;
	packet.t_1 = t_1;
	packet.r_1 = r_1;
	packet.p_1 = p_1;
	packet.y_1 = y_1;
	packet.pwm_1 = pwm_1;
	packet.t_2 = t_2;
	packet.r_2 = r_2;
	packet.p_2 = p_2;
	packet.y_2 = y_2;
	packet.pwm_2 = pwm_2;
	packet.t_3 = t_3;
	packet.r_3 = r_3;
	packet.p_3 = p_3;
	packet.y_3 = y_3;
	packet.pwm_3 = pwm_3;
	packet.t_4 = t_4;
	packet.r_4 = r_4;
	packet.p_4 = p_4;
	packet.y_4 = y_4;
	packet.pwm_4 = pwm_4;
	packet.t_5 = t_5;
	packet.r_5 = r_5;
	packet.p_5 = p_5;
	packet.y_5 = y_5;
	packet.pwm_5 = pwm_5;
	packet.t_6 = t_6;
	packet.r_6 = r_6;
	packet.p_6 = p_6;
	packet.y_6 = y_6;
	packet.pwm_6 = pwm_6;
	packet.mode_1 = mode_1;
	packet.mode_2 = mode_2;
	packet.mode_3 = mode_3;
	packet.mode_4 = mode_4;
	packet.mode_5 = mode_5;
	packet.mode_6 = mode_6;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VICON_6Q, (const char *)&packet, 66, 74);
#endif
}

#endif

// MESSAGE VICON_6Q UNPACKING


/**
 * @brief Get field mode_1 from vicon_6q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_6q_get_mode_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  60);
}

/**
 * @brief Get field t_1 from vicon_6q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_t_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field r_1 from vicon_6q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_r_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field p_1 from vicon_6q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_p_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field y_1 from vicon_6q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_y_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field pwm_1 from vicon_6q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_pwm_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field mode_2 from vicon_6q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_6q_get_mode_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  61);
}

/**
 * @brief Get field t_2 from vicon_6q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_t_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field r_2 from vicon_6q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_r_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field p_2 from vicon_6q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_p_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field y_2 from vicon_6q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_y_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field pwm_2 from vicon_6q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_pwm_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field mode_3 from vicon_6q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_6q_get_mode_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  62);
}

/**
 * @brief Get field t_3 from vicon_6q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_t_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field r_3 from vicon_6q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_r_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field p_3 from vicon_6q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_p_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field y_3 from vicon_6q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_y_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field pwm_3 from vicon_6q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_pwm_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field mode_4 from vicon_6q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_6q_get_mode_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  63);
}

/**
 * @brief Get field t_4 from vicon_6q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_t_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field r_4 from vicon_6q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_r_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field p_4 from vicon_6q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_p_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  34);
}

/**
 * @brief Get field y_4 from vicon_6q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_y_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  36);
}

/**
 * @brief Get field pwm_4 from vicon_6q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_pwm_4(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  38);
}

/**
 * @brief Get field mode_5 from vicon_6q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_6q_get_mode_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  64);
}

/**
 * @brief Get field t_5 from vicon_6q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_t_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field r_5 from vicon_6q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_r_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  42);
}

/**
 * @brief Get field p_5 from vicon_6q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_p_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  44);
}

/**
 * @brief Get field y_5 from vicon_6q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_y_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  46);
}

/**
 * @brief Get field pwm_5 from vicon_6q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_pwm_5(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  48);
}

/**
 * @brief Get field mode_6 from vicon_6q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_6q_get_mode_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  65);
}

/**
 * @brief Get field t_6 from vicon_6q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_t_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  50);
}

/**
 * @brief Get field r_6 from vicon_6q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_r_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  52);
}

/**
 * @brief Get field p_6 from vicon_6q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_p_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  54);
}

/**
 * @brief Get field y_6 from vicon_6q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_y_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  56);
}

/**
 * @brief Get field pwm_6 from vicon_6q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_6q_get_pwm_6(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  58);
}

/**
 * @brief Decode a vicon_6q message into a struct
 *
 * @param msg The message to decode
 * @param vicon_6q C-struct to decode the message contents into
 */
static inline void mavlink_msg_vicon_6q_decode(const mavlink_message_t* msg, mavlink_vicon_6q_t* vicon_6q)
{
#if MAVLINK_NEED_BYTE_SWAP
	vicon_6q->t_1 = mavlink_msg_vicon_6q_get_t_1(msg);
	vicon_6q->r_1 = mavlink_msg_vicon_6q_get_r_1(msg);
	vicon_6q->p_1 = mavlink_msg_vicon_6q_get_p_1(msg);
	vicon_6q->y_1 = mavlink_msg_vicon_6q_get_y_1(msg);
	vicon_6q->pwm_1 = mavlink_msg_vicon_6q_get_pwm_1(msg);
	vicon_6q->t_2 = mavlink_msg_vicon_6q_get_t_2(msg);
	vicon_6q->r_2 = mavlink_msg_vicon_6q_get_r_2(msg);
	vicon_6q->p_2 = mavlink_msg_vicon_6q_get_p_2(msg);
	vicon_6q->y_2 = mavlink_msg_vicon_6q_get_y_2(msg);
	vicon_6q->pwm_2 = mavlink_msg_vicon_6q_get_pwm_2(msg);
	vicon_6q->t_3 = mavlink_msg_vicon_6q_get_t_3(msg);
	vicon_6q->r_3 = mavlink_msg_vicon_6q_get_r_3(msg);
	vicon_6q->p_3 = mavlink_msg_vicon_6q_get_p_3(msg);
	vicon_6q->y_3 = mavlink_msg_vicon_6q_get_y_3(msg);
	vicon_6q->pwm_3 = mavlink_msg_vicon_6q_get_pwm_3(msg);
	vicon_6q->t_4 = mavlink_msg_vicon_6q_get_t_4(msg);
	vicon_6q->r_4 = mavlink_msg_vicon_6q_get_r_4(msg);
	vicon_6q->p_4 = mavlink_msg_vicon_6q_get_p_4(msg);
	vicon_6q->y_4 = mavlink_msg_vicon_6q_get_y_4(msg);
	vicon_6q->pwm_4 = mavlink_msg_vicon_6q_get_pwm_4(msg);
	vicon_6q->t_5 = mavlink_msg_vicon_6q_get_t_5(msg);
	vicon_6q->r_5 = mavlink_msg_vicon_6q_get_r_5(msg);
	vicon_6q->p_5 = mavlink_msg_vicon_6q_get_p_5(msg);
	vicon_6q->y_5 = mavlink_msg_vicon_6q_get_y_5(msg);
	vicon_6q->pwm_5 = mavlink_msg_vicon_6q_get_pwm_5(msg);
	vicon_6q->t_6 = mavlink_msg_vicon_6q_get_t_6(msg);
	vicon_6q->r_6 = mavlink_msg_vicon_6q_get_r_6(msg);
	vicon_6q->p_6 = mavlink_msg_vicon_6q_get_p_6(msg);
	vicon_6q->y_6 = mavlink_msg_vicon_6q_get_y_6(msg);
	vicon_6q->pwm_6 = mavlink_msg_vicon_6q_get_pwm_6(msg);
	vicon_6q->mode_1 = mavlink_msg_vicon_6q_get_mode_1(msg);
	vicon_6q->mode_2 = mavlink_msg_vicon_6q_get_mode_2(msg);
	vicon_6q->mode_3 = mavlink_msg_vicon_6q_get_mode_3(msg);
	vicon_6q->mode_4 = mavlink_msg_vicon_6q_get_mode_4(msg);
	vicon_6q->mode_5 = mavlink_msg_vicon_6q_get_mode_5(msg);
	vicon_6q->mode_6 = mavlink_msg_vicon_6q_get_mode_6(msg);
#else
	memcpy(vicon_6q, _MAV_PAYLOAD(msg), 66);
#endif
}

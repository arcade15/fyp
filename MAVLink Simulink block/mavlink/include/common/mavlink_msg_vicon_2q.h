// MESSAGE VICON_2Q PACKING

#define MAVLINK_MSG_ID_VICON_2Q 222

typedef struct __mavlink_vicon_2q_t
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
 uint8_t mode_1; ///< Quad ID
 uint8_t mode_2; ///< Quad ID
} mavlink_vicon_2q_t;

#define MAVLINK_MSG_ID_VICON_2Q_LEN 22
#define MAVLINK_MSG_ID_222_LEN 22



#define MAVLINK_MESSAGE_INFO_VICON_2Q { \
	"VICON_2Q", \
	12, \
	{  { "t_1", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_vicon_2q_t, t_1) }, \
         { "r_1", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_vicon_2q_t, r_1) }, \
         { "p_1", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_vicon_2q_t, p_1) }, \
         { "y_1", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_vicon_2q_t, y_1) }, \
         { "pwm_1", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_vicon_2q_t, pwm_1) }, \
         { "t_2", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_vicon_2q_t, t_2) }, \
         { "r_2", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_vicon_2q_t, r_2) }, \
         { "p_2", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_vicon_2q_t, p_2) }, \
         { "y_2", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_vicon_2q_t, y_2) }, \
         { "pwm_2", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_vicon_2q_t, pwm_2) }, \
         { "mode_1", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_vicon_2q_t, mode_1) }, \
         { "mode_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_vicon_2q_t, mode_2) }, \
         } \
}


/**
 * @brief Pack a vicon_2q message
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
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_2q_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t mode_1, int16_t t_1, int16_t r_1, int16_t p_1, int16_t y_1, int16_t pwm_1, uint8_t mode_2, int16_t t_2, int16_t r_2, int16_t p_2, int16_t y_2, int16_t pwm_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[22];
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
	_mav_put_uint8_t(buf, 20, mode_1);
	_mav_put_uint8_t(buf, 21, mode_2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 22);
#else
	mavlink_vicon_2q_t packet;
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
	packet.mode_1 = mode_1;
	packet.mode_2 = mode_2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 22);
#endif

	msg->msgid = MAVLINK_MSG_ID_VICON_2Q;
	return mavlink_finalize_message(msg, system_id, component_id, 22, 113);
}

/**
 * @brief Pack a vicon_2q message on a channel
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
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_2q_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode_1,int16_t t_1,int16_t r_1,int16_t p_1,int16_t y_1,int16_t pwm_1,uint8_t mode_2,int16_t t_2,int16_t r_2,int16_t p_2,int16_t y_2,int16_t pwm_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[22];
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
	_mav_put_uint8_t(buf, 20, mode_1);
	_mav_put_uint8_t(buf, 21, mode_2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 22);
#else
	mavlink_vicon_2q_t packet;
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
	packet.mode_1 = mode_1;
	packet.mode_2 = mode_2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 22);
#endif

	msg->msgid = MAVLINK_MSG_ID_VICON_2Q;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 22, 113);
}

/**
 * @brief Encode a vicon_2q struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vicon_2q C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vicon_2q_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vicon_2q_t* vicon_2q)
{
	return mavlink_msg_vicon_2q_pack(system_id, component_id, msg, vicon_2q->mode_1, vicon_2q->t_1, vicon_2q->r_1, vicon_2q->p_1, vicon_2q->y_1, vicon_2q->pwm_1, vicon_2q->mode_2, vicon_2q->t_2, vicon_2q->r_2, vicon_2q->p_2, vicon_2q->y_2, vicon_2q->pwm_2);
}

/**
 * @brief Send a vicon_2q message
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
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vicon_2q_send(mavlink_channel_t chan, uint8_t mode_1, int16_t t_1, int16_t r_1, int16_t p_1, int16_t y_1, int16_t pwm_1, uint8_t mode_2, int16_t t_2, int16_t r_2, int16_t p_2, int16_t y_2, int16_t pwm_2)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[22];
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
	_mav_put_uint8_t(buf, 20, mode_1);
	_mav_put_uint8_t(buf, 21, mode_2);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VICON_2Q, buf, 22, 113);
#else
	mavlink_vicon_2q_t packet;
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
	packet.mode_1 = mode_1;
	packet.mode_2 = mode_2;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VICON_2Q, (const char *)&packet, 22, 113);
#endif
}

#endif

// MESSAGE VICON_2Q UNPACKING


/**
 * @brief Get field mode_1 from vicon_2q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_2q_get_mode_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field t_1 from vicon_2q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_t_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field r_1 from vicon_2q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_r_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field p_1 from vicon_2q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_p_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field y_1 from vicon_2q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_y_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field pwm_1 from vicon_2q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_pwm_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field mode_2 from vicon_2q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_2q_get_mode_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field t_2 from vicon_2q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_t_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field r_2 from vicon_2q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_r_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field p_2 from vicon_2q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_p_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field y_2 from vicon_2q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_y_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field pwm_2 from vicon_2q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_2q_get_pwm_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Decode a vicon_2q message into a struct
 *
 * @param msg The message to decode
 * @param vicon_2q C-struct to decode the message contents into
 */
static inline void mavlink_msg_vicon_2q_decode(const mavlink_message_t* msg, mavlink_vicon_2q_t* vicon_2q)
{
#if MAVLINK_NEED_BYTE_SWAP
	vicon_2q->t_1 = mavlink_msg_vicon_2q_get_t_1(msg);
	vicon_2q->r_1 = mavlink_msg_vicon_2q_get_r_1(msg);
	vicon_2q->p_1 = mavlink_msg_vicon_2q_get_p_1(msg);
	vicon_2q->y_1 = mavlink_msg_vicon_2q_get_y_1(msg);
	vicon_2q->pwm_1 = mavlink_msg_vicon_2q_get_pwm_1(msg);
	vicon_2q->t_2 = mavlink_msg_vicon_2q_get_t_2(msg);
	vicon_2q->r_2 = mavlink_msg_vicon_2q_get_r_2(msg);
	vicon_2q->p_2 = mavlink_msg_vicon_2q_get_p_2(msg);
	vicon_2q->y_2 = mavlink_msg_vicon_2q_get_y_2(msg);
	vicon_2q->pwm_2 = mavlink_msg_vicon_2q_get_pwm_2(msg);
	vicon_2q->mode_1 = mavlink_msg_vicon_2q_get_mode_1(msg);
	vicon_2q->mode_2 = mavlink_msg_vicon_2q_get_mode_2(msg);
#else
	memcpy(vicon_2q, _MAV_PAYLOAD(msg), 22);
#endif
}

use crate::{log::octo_log, log_level::LogLevel};
use std::ffi::c_char;

/// # Safety
///
/// `context` and `message` must be valid C strings.
#[unsafe(no_mangle)]
pub unsafe extern "C" fn log_warn(context: *const c_char, message: *const c_char) {
    unsafe { octo_log(context, message, LogLevel::Warn) };
}

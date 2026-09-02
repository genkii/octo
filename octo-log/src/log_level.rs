use std::sync::atomic::{AtomicU8, Ordering};

#[repr(C)]
#[derive(Clone, Copy)]
pub enum LogLevel {
    Trace,
    Debug,
    Info,
    Warn,
    Error,
}

pub static MIN_LEVEL: AtomicU8 = AtomicU8::new(LogLevel::Info as u8);

#[unsafe(no_mangle)]
pub extern "C" fn log_set_level(level: LogLevel) {
    MIN_LEVEL.store(level as u8, Ordering::Relaxed);
}

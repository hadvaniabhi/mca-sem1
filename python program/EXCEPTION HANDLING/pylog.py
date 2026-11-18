# Configure the logging settings
logging.basicConfig(
    filename="app.log",
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(module)s:%(lineno)d - %(message)s",
)

# Create a logger object
logger = logging.getLogger(__name__)


def divide_numbers(a: float, b: float) -> float:
    logger.info("Attempting to divide %s by %s", a, b)
    try:
        result = a / b
        logger.info("Division successful. Result: %s", result)
        return result
    except ZeroDivisionError:
        # logger.exception automatically captures and logs the full stack trace
        logger.exception("Division failed: Attempted to divide by zero.")
        raise
    except TypeError as e:
        # Use logger.error with exc_info=True to manually include tracebacks
        logger.error("Type error encountered: %s", e, exc_info=True)
        raise


if __name__ == "__main__":
    # Successful execution
    try:
        divide_numbers(10, 2)
    except Exception:
        pass

    # Triggers ZeroDivisionError (logged with full traceback)
    try:
        divide_numbers(10, 0)
    except ZeroDivisionError:
        print("Handled ZeroDivisionError in main application flow.")

    # Triggers TypeError (logged with explicit exc_info)
    try:
        divide_numbers(10, "two")  # type: ignore
    except TypeError:
        print("Handled TypeError in main application flow.")
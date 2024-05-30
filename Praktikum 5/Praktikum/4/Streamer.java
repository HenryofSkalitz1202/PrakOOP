import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class Streamer<T> implements IStreamer<T> {
    private List<T> data;

    public Streamer(List<T> data) {
        this.data = data;
    }

    @Override
    public List<T> collect() {
        return this.data;
    }

    @Override
    public void forEach(Function<T, Void> consumer) {
        for (T item : data) {
            consumer.apply(item);
        }
    }

    @Override
    public <R> IStreamer<R> map(Function<T, R> mapper) {
        List<R> mappedData = new ArrayList<>();
        for (T item : data) {
            mappedData.add(mapper.apply(item));
        }
        return new Streamer<>(mappedData);
    }

    @Override
    public IStreamer<T> filter(Function<T, Boolean> predicate) {
        List<T> filteredData = new ArrayList<>();
        for (T item : data) {
            if (predicate.apply(item)) {
                filteredData.add(item);
            }
        }
        return new Streamer<>(filteredData);
    }

    @Override
    public <R> R reduce(R initialValue, Function<R, Function<T, R>> reducer) {
        R accumulator = initialValue;
        for (T item : data) {
            accumulator = reducer.apply(accumulator).apply(item);
        }
        return accumulator;
    }

    @Override
    public <R> IStreamer<R> flatMap(Function<T, IStreamer<R>> mapper) {
        List<R> flatMappedData = new ArrayList<>();
        for (T item : data) {
            IStreamer<R> mappedStream = mapper.apply(item);
            List<R> mappedList = mappedStream.collect();
            flatMappedData.addAll(mappedList);
        }
        return new Streamer<>(flatMappedData);
    }

    @Override
    public T findFirst(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (predicate.apply(item)) {
                return item;
            }
        }
        return null;
    }

    @Override
    public T findLast(Function<T, Boolean> predicate) {
        T lastMatch = null;
        for (T item : data) {
            if (predicate.apply(item)) {
                lastMatch = item;
            }
        }
        return lastMatch;
    }

    @Override
    public T head() {
        if (data.isEmpty()) {
            return null;
        }
        return data.get(0);
    }

    @Override
    public IStreamer<T> tail() {
        if (data.isEmpty()) {
            return new Streamer<>(new ArrayList<>());
        }
        return new Streamer<>(data.subList(1, data.size()));
    }

    @Override
    public T last() {
        if (data.isEmpty()) {
            return null;
        }
        return data.get(data.size() - 1);
    }

    @Override
    public IStreamer<T> init() {
        if (data.isEmpty()) {
            return new Streamer<>(new ArrayList<>());
        }
        return new Streamer<>(data.subList(0, data.size() - 1));
    }

    @Override
    public IStreamer<T> takeFirst(int n) {
        if (n >= data.size()) {
            return new Streamer<>(data);
        }
        return new Streamer<>(data.subList(0, n));
    }

    @Override
    public IStreamer<T> takeLast(int n) {
        if (n >= data.size()) {
            return new Streamer<>(data);
        }
        return new Streamer<>(data.subList(data.size() - n, data.size()));
    }

    @Override
    public Boolean isEmpty() {
        return data.isEmpty();
    }

    @Override
    public Integer count() {
        return data.size();
    }

    @Override
    public Boolean some(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (predicate.apply(item)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public Boolean every(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (!predicate.apply(item)) {
                return false;
            }
        }
        return true;
    }

    @Override
    public void reverse() {
        List<T> result = new ArrayList<>();
        for (int i = this.data.size() - 1; i >= 0; i--) {
            result.add(this.data.get(i));
        }
        this.data = result;
    }
}